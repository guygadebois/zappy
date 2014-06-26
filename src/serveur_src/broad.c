/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   broadcast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbodovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/19 05:21:50 by sbodovsk          #+#    #+#             */
/*   Updated: 2014/06/26 17:26:26 by sbodovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <math.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

static int	ft_orient(double rad)
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

static int	ft_getresbyorient(t_trant *emet, t_trant *others, int orient)
{
	int		res;

	res = 0;
	if (orient == 1)
		res = ft_orient((2 * M_PI) - atan2(fabs(emet->x
						- others->x), (emet->y - others->y)));
	else if (orient == 2)
		res = ft_orient(atan2(fabs(emet->x
						- others->x), (emet->y - others->y)));
	else if (orient == 3)
		res = ft_orient(atan2(fabs(emet->x
						- others->x), (emet->y - others->y)) + M_PI);
	else if (orient == 4)
		res = ft_orient(M_PI - atan2(fabs(emet->x
						- others->x), (emet->y - others->y)));
	return (res);
}

static int	ft_getresultat(t_data *game, t_trant *emet, t_list *others, int res)
{
	int			orient;

	orient = 0;
	orient = ft_quadrant(emet->x,
			((t_trant*)others->content)->x, emet->y,
			((t_trant*)others)->y);
	res = ft_getresbyorient(emet, (t_trant*)others->content,
			orient);
	res = ft_sym(game, emet, (t_trant*)others->content, res);
	res = (res + 4 + ((((t_trant *)others->content)->direct + 3) % 4) * 2) % 8;
	if (res == 0)
		res = 8;
	if ((emet->x == ((t_trant*)others->content)->x)
			&& (emet->y == ((t_trant*)others->content)->y))
		res = 0;
	return (res);
}

static void	ft_prepare(t_data *game, t_trant *emet, int sock, char *msg)
{
	ft_strcat(emet->cmd_out, "ok\n");
	ft_strcat(game->visu.cmd_out, "pbc ");
	ft_strcat(game->visu.cmd_out, ft_itoa(sock));
	ft_strcat(game->visu.cmd_out, " ");
	ft_strcat(game->visu.cmd_out, msg);
	ft_strcat(game->visu.cmd_out, "\n");
}

void		broadcast(t_data *game, char *msg, int sock)
{
	t_trant		*emet;
	t_list		*others;
	int			res;
	char		*result;

	res = 0;
	emet = sv_getclientbysock(game, sock);
	ft_prepare(game, emet, sock, msg);
	others = (t_list *)game->trant;
	while (others != NULL)
	{
		if (((t_trant*)others->content)->sock != sock)
		{
			res = ft_getresultat(game, emet, others, res);
			result = ft_strstrjoin(5, "message ",
						ft_itoa(res), ", ", msg, "\n");
			ft_strcat(((t_trant*)others->content)->cmd_out, result);
		}
		others = others->next;
	}
}
