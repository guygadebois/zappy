/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/18 13:22:40 by bjacob            #+#    #+#             */
/*   Updated: 2014/06/26 14:27:48 by bjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "libft.h"
#include "types.h"
#include "server.h"

static void	ft_send_buf(int obj, t_trant *trant, t_data *game, t_area ***map)
{
	int	x;
	int	y;

	x = trant->x;
	y = trant->y;
	ft_strcat(trant->cmd_out, "ok\n");
	ft_strstrcat(game->visu.cmd_out, "pdr ", 2, trant->sock, obj);
	ft_strstrcat(game->visu.cmd_out, "pin ", 10, trant->sock, trant->x,
		trant->y, trant->life, trant->lin, trant->der,
		trant->sib, trant->men, trant->phi, trant->thy);
	ft_strstrcat(game->visu.cmd_out, "bct", 9, trant->x, trant->y,
		map[x][y]->food, map[x][y]->linemate, map[x][y]->deraumere,
		map[x][y]->sibur, map[x][y]->mendiane, map[x][y]->phiras,\
		map[x][y]->thystame);
}

static void	ft_take_der_sib(t_area ***map, t_trant *trant, char *obj,
		t_data *game)
{
	if (ft_strcmp(obj, "deraumere") == 0)
	{
		if (map[trant->x][trant->y]->deraumere > 0)
		{
			map[trant->x][trant->y]->deraumere--;
			trant->der++;
			ft_send_buf(2, trant, game, map);
		}
		else
			ft_strcat(trant->cmd_out, "ko\n");
	}
	if (ft_strcmp(obj, "sibur") == 0)
	{
		if (map[trant->x][trant->y]->sibur > 0)
		{
			map[trant->x][trant->y]->sibur--;
			trant->sib++;
			ft_send_buf(3, trant, game, map);
		}
		else
			ft_strcat(trant->cmd_out, "ko\n");
	}
}

static void	ft_take_men_phi(t_area ***map, t_trant *trant, char *obj,
		t_data *game)
{
	if (ft_strcmp(obj, "mendiane") == 0)
	{
		if (map[trant->x][trant->y]->mendiane > 0)
		{
			map[trant->x][trant->y]->mendiane--;
			trant->men++;
			ft_send_buf(4, trant, game, map);
		}
		else
			ft_strcat(trant->cmd_out, "ko\n");
	}
	if (ft_strcmp(obj, "phiras") == 0)
	{
		if (map[trant->x][trant->y]->phiras > 0)
		{
			map[trant->x][trant->y]->phiras--;
			trant->phi++;
			ft_send_buf(5, trant, game, map);
		}
		else
			ft_strcat(trant->cmd_out, "ko\n");
	}
}

static void	ft_take_thy(t_area ***map, t_trant *trant, char *obj,
		t_data *game)
{
	if (ft_strcmp(obj, "thystame") == 0)
	{
		if (map[trant->x][trant->y]->thystame > 0)
		{
			map[trant->x][trant->y]->thystame--;
			trant->thy++;
			ft_send_buf(6, trant, game, map);
		}
		else
			ft_strcat(trant->cmd_out, "ko\n");
	}
	if (ft_strcmp(obj, "linemate") == 0)
	{
		if (map[trant->x][trant->y]->linemate > 0)
		{
			map[trant->x][trant->y]->linemate--;
			trant->lin++;
			ft_send_buf(1, trant, game, map);
		}
		else
			ft_strcat(trant->cmd_out, "ko\n");
	}
}

void		ft_take_obj(t_area ***map, t_trant *trant, char *obj,
		t_data *game)
{
	if (ft_strcmp(obj, "nourriture") == 0)
	{
		if (map[trant->x][trant->y]->food > 0)
		{
			map[trant->x][trant->y]->food--;
			trant->life++;
			ft_place_food_bis(game, game->length, game->width, 1);
			ft_send_buf(0, trant, game, map);
		}
		else
			ft_strcat(trant->cmd_out, "ko\n");
	}
	ft_take_der_sib(map, trant, obj, game);
	ft_take_men_phi(map, trant, obj, game);
	ft_take_thy(map, trant, obj, game);
}
