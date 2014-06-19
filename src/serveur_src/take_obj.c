/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/18 13:22:40 by bjacob            #+#    #+#             */
/*   Updated: 2014/06/18 13:40:11 by bjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "libft.h"

static void	ft_take_der_sib(t_area ***map, t_trant *trant, char *obj)
{
	if (ft_strcmp(obj, "deraumere") == 0)
	{
		if (map[trant->x][trant->y]->deraumere > 0)
		{
			map[trant->x][trant->y]->deraumere--;
			trant->der++;
			ft_putendl("ok");
		}
		else
			ft_putendl("ko");
	}
	if (ft_strcmp(obj, "sibur") == 0)
	{
		if (map[trant->x][trant->y]->sibur > 0)
		{
			map[trant->x][trant->y]->sibur--;
			trant->sib++;
			ft_putendl("ok");
		}
		else
			ft_putendl("ko");
	}
}

static void	ft_take_men_phi(t_area ***map, t_trant *trant, char *obj)
{
	if (ft_strcmp(obj, "mendiane") == 0)
	{
		if (map[trant->x][trant->y]->mendiane > 0)
		{
			map[trant->x][trant->y]->mendiane--;
			trant->men++;
			ft_putendl("ok");
		}
		else
			ft_putendl("ko");
	}
	if (ft_strcmp(obj, "phiras") == 0)
	{
		if (map[trant->x][trant->y]->phiras > 0)
		{
			map[trant->x][trant->y]->phiras--;
			trant->phi++;
			ft_putendl("ok");
		}
		else
			ft_putendl("ko");
	}
}

static void	ft_take_thy(t_area ***map, t_trant *trant, char *obj)
{
	if (ft_strcmp(obj, "thystame") == 0)
	{
		if (map[trant->x][trant->y]->thystame > 0)
		{
			map[trant->x][trant->y]->thystame--;
			trant->thy++;
			ft_putendl("ok");
		}
		else
			ft_putendl("ko");
	}
}

void		ft_take_obj(t_area ***map, t_trant *trant, char *obj)
{
	if (ft_strcmp(obj, "nourriture") == 0)
	{
		if (map[trant->x][trant->y]->food > 0)
		{
			map[trant->x][trant->y]->food--;
			trant->life++;
			ft_putendl("ok");
		}
		else
			ft_putendl("ko");
	}
	if (ft_strcmp(obj, "linemate") == 0)
	{
		if (map[trant->x][trant->y]->linemate > 0)
		{
			map[trant->x][trant->y]->linemate--;
			trant->lin++;
			ft_putendl("ok");
		}
		else
			ft_putendl("ko");
	}
	ft_take_der_sib(map, trant, obj);
	ft_take_men_phi(map, trant, obj);
	ft_take_thy(map, trant, obj);
}
