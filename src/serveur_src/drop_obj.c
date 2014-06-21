/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drop_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/18 13:22:40 by bjacob            #+#    #+#             */
/*   Updated: 2014/06/21 16:28:46 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "server.h"
#include "types.h"
#include "libft.h"

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

static void	ft_drop_der_sib(t_area ***map, t_trant *trant, char *obj,
		t_data *game)
{
	if (ft_strcmp(obj, "deraumere") == 0)
	{
		if (trant->der > 0)
		{
			map[trant->x][trant->y]->deraumere++;
			trant->der--;
			ft_send_buf(2, trant, game, map);
		}
		else
			ft_strcat(trant->cmd_out, "ko\n");
	}
	if (ft_strcmp(obj, "sibur") == 0)
	{
		if (trant->sib > 0)
		{
			map[trant->x][trant->y]->sibur++;
			trant->sib--;
			ft_send_buf(3, trant, game, map);
		}
		else
			ft_strcat(trant->cmd_out, "ko\n");
	}
}

static void	ft_drop_men_phi(t_area ***map, t_trant *trant, char *obj,
		t_data *game)
{
	if (ft_strcmp(obj, "mendiane") == 0)
	{
		if (trant->men > 0)
		{
			map[trant->x][trant->y]->mendiane++;
			trant->men--;
			ft_send_buf(4, trant, game, map);
		}
		else
			ft_strcat(trant->cmd_out, "ko\n");
	}
	if (ft_strcmp(obj, "phiras") == 0)
	{
		if (trant->phi > 0)
		{
			map[trant->x][trant->y]->phiras++;
			trant->phi--;
			ft_send_buf(5, trant, game, map);
		}
		else
			ft_strcat(trant->cmd_out, "ko\n");
	}
}

static void	ft_drop_thy(t_area ***map, t_trant *trant, char *obj,
		t_data *game)
{
	if (ft_strcmp(obj, "thystame") == 0)
	{
		if (trant->thy > 0)
		{
			map[trant->x][trant->y]->thystame++;
			trant->thy--;
			ft_send_buf(6, trant, game, map);
		}
		else
			ft_strcat(trant->cmd_out, "ko\n");
	}
}

void		ft_drop_obj(t_area ***map, t_trant *trant, char *obj,
		t_data *game)
{
	if (ft_strcmp(obj, "nourriture") == 0)
	{
		if (trant->life > 0)
		{
			map[trant->x][trant->y]->food++;
			trant->life--;
			ft_send_buf(0, trant, game, map);
		}
		else
			ft_strcat(trant->cmd_out, "ko\n");
	}
	if (ft_strcmp(obj, "linemate") == 0)
	{
		if (trant->lin > 0)
		{
			map[trant->x][trant->y]->linemate++;
			trant->lin--;
			ft_send_buf(1, trant, game, map);
		}
		else
			ft_strcat(trant->cmd_out, "ko\n");
	}
	ft_drop_der_sib(map, trant, obj, game);
	ft_drop_men_phi(map, trant, obj, game);
	ft_drop_thy(map, trant, obj, game);
}
