/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   broad2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbodovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 17:18:16 by sbodovsk          #+#    #+#             */
/*   Updated: 2014/06/26 17:22:19 by sbodovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "server.h"
#include <math.h>

int			ft_quadrant(int xa, int xb, int ya, int yb)
{
	if ((xa < xb) && (ya < yb))
		return (1);
	else if ((xa < xb) && (ya > yb))
		return (2);
	else if ((xa > xb) && (ya < yb))
		return (3);
	return (4);
}

static int	ft_sym_x(int res)
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

static int	ft_sym_y(int res)
{
	if (res == 8)
		res = 2;
	else if (res == 7)
		res = 3;
	else if (res == 6)
		res = 4;
	else if (res == 4)
		res = 6;
	else if (res == 3)
		res = 7;
	else if (res == 2)
		res = 8;
	return (res);
}

int			ft_sym(t_data *game, t_trant *emet, t_trant *others, int res)
{
	if (fabs(emet->x - others->x) > (game->length / 2))
		res = ft_sym_x(res);
	if (fabs(emet->y - others->y) > (game->width / 2))
		res = ft_sym_y(res);
	return (res);
}
