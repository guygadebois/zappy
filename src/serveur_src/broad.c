/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   broadcast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbodovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/19 05:21:50 by sbodovsk          #+#    #+#             */
/*   Updated: 2014/06/26 16:16:20 by sbodovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <math.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#include <stdio.h>

int		ft_quadrant(int xa, int xb, int ya, int yb)
{
	if ((xa < xb) && (ya < yb))
		return (1);
	else if ((xa < xb) && (ya > yb))
		return (2);
	else if ((xa > xb) && (ya < yb))
		return (3);
	return (4);
}

int		ft_sym_x(int res)
{
	if (res == 8)
		res = 6;
	else if (res == 1)
		res = 5;
	else if (res == 2)
		res = 4;
	else if (res == 4)
		res = 2;
	else if (res == 5)
		res = 1;
	else if (res == 6)
		res = 8;
	return (res);
}

int		ft_sym_y(int res)
{
	if (res == 8)
		res = 2;
	else if (res == 7)
		res = 3;
	else if (res == 6)
		res = 4;
	else if (res == 4)
		res = 6;
	else if (res == 7)
		res = 3;
	else if (res == 2)
		res = 8;
	return (res);
}

int		ft_orient(double rad)
{
	if ((rad > 0) && (rad < M_PI_4))
		return (7);
	else if (rad == M_PI_4)
		return (8);
	else if ((rad > M_PI_4) && (rad < (3 * M_PI_4)))
		return (1);
	else if (rad == (3 * M_PI_4))
		return (2);
	else if ((rad > (3 * M_PI_4)) && (rad < (5 * M_PI_4)))
		return (3);
	else if (rad == (5 * M_PI_4))
		return (4);
	else if ((rad > (5 * M_PI_4)) && (rad < (7 * M_PI_4)))
		return (5);
	return (6);
}

int		ft_getresbyorient(t_trant *emet, t_trant *others, int orient)
{
	int		res;

	res = 0;
	if (orient == 1)
		res = ft_orient((2 * M_PI) - atan2(fabs(emet->x - others->x), (emet->y - others->y)));
	else if (orient == 2)
		res = ft_orient(atan2(fabs(emet->x - others->x), (emet->y - others->y)));
	else if (orient == 3)
		res = ft_orient(atan2(fabs(emet->x - others->x), (emet->y - others->y)) + M_PI);
	else if (orient == 4)
		res = ft_orient(M_PI - atan2(fabs(emet->x - others->x), (emet->y - others->y)));
	return (res);
}

int		ft_sym(t_data *game, t_trant *emet, t_trant *others, int res)
{
	if (fabs(emet->x - others->x) > game->width)
		res = ft_sym_x(res);
	if (fabs(emet->y - others->y) > game->length)
		res = ft_sym_y(res);
	return (res);
}

void	broadcast(t_data *game, char *msg, int sock)
{
	t_trant		*emet;
	t_list		*others;
	int			orient;
	int			res;
	char		*result;

	orient = 0;
	res = 0;
	emet = sv_getclientbysock(game, sock);
	ft_strcat(emet->cmd_out, "ok\n");
	ft_strcat(game->visu.cmd_out, "pbc "); 
	ft_strcat(game->visu.cmd_out, ft_itoa(sock));
	ft_strcat(game->visu.cmd_out, " "); 
	ft_strcat(game->visu.cmd_out, msg); 
	ft_strcat(game->visu.cmd_out, "\n");
   printf("%s\n", msg);	
	others = (t_list *)game->trant;
	while (others != NULL)
	{
		if (((t_trant*)others->content)->sock != sock)
		{
			printf("emet->x : %d , emet->y : %d , others->x : %d , others->y : %d , others->direct : %d \n", emet->x, emet->y, ((t_trant*)others)->x, ((t_trant*)others)->y, (((t_trant*)others->content)->direct));
			orient = ft_quadrant(emet->x,
					((t_trant*)others->content)->x, emet->y,
					((t_trant*)others)->y);
			res = ft_getresbyorient(emet, (t_trant*)others->content,
					orient);
//			res = ft_sym(game, emet, (t_trant*)others->content, res);
			res = (res + 4 + ((((t_trant*)others->content)->direct + 3) % 4 ) * 2) % 8;
			if (res == 0)
				res = 8;
			if ((emet->x == ((t_trant*)others->content)->x)
					&& (emet->y == ((t_trant*)others->content)->y))
				res = 0;
			result = ft_strstrjoin(5, "message ", ft_itoa(res), ", ", msg, "\n");
			ft_strcat(((t_trant*)others->content)->cmd_out, result);
		}
		others = others->next;
	}
}
