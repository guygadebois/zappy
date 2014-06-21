/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   broadcast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbodovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/19 05:21:50 by sbodovsk          #+#    #+#             */
/*   Updated: 2014/06/21 05:36:02 by sbodovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <math.h>
#include <stdarg.h>
#include <string.h>

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
}

char	*ft_strstrjoin(int nb, ...)
{
	va_list		ap;
	char		*str;
	char		*ptr;
	char		*tmp;

	va_start(ap, nb);
	ptr = ft_strnew(1);
	if (ptr == NULL || nb < 0)
		return (NULL);
	while (nb > 0)
	{
		str = ft_strdup(va_arg(ap, char *));
		tmp = ptr;
		ptr = ft_strjoin(tmp, str);
		free(str);
		free(tmp);
		nb--;
	}
	va_end(ap);
	return (ptr);
}

void	broadcast(t_data *game, char *msg, int sock)
{
	t_trant		*emet;
	t_trant		*others;
	int			orient;
	int			res;
	char		*result;

	orient = 0;
	res = 0;
	emet = sv_getclientbysock(sock);
	others = (t_trant *)game->trant;
	while (others != NULL)
	{
		if (others->sock != sock)
			orient = ft_quadrant(emet->x, others->x, emet->y, others->y);
		res = ft_getresbyorient(emet, others, orient);
		res = ft_sym(game, emet, others, res);
		res = (res + 4 + others->direct) % 8;
		if (res == 0)
			res = 8;
		if ((emet->x == others->x) && (emet->y == others->y))
			res = 0;
		result = ft_strstrjoin(4, "message ", ft_itoa(res), ", ", msg);
		others->cmd_out = result;
		others = others->next;
	}
}
