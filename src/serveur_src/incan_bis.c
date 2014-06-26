/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   incan_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcouly <dcouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 14:55:24 by dcouly            #+#    #+#             */
/*   Updated: 2014/06/26 15:01:16 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "types.h"
#include "server.h"
#include "map.h"
#include "libft.h"

int			sv_nb_player(t_data *game, t_trant *trant)
{
	int				nb;
	t_list_trant	*tra_lst;
	t_trant			*tra;

	nb = 0;
	tra_lst = game->map[trant->x][trant->y]->list_player;
	while (tra_lst)
	{
		tra = (tra_lst->player);
		if (tra->sock != trant->sock && trant->level == tra->level
				&& !ft_strcmp(tra->team, trant->team) && !trant->is_incan)
			nb++;
		tra_lst = tra_lst->next;
	}
	return (nb);
}

void		ft_pic(t_data *game, t_trant *trant, int lvl)
{
	trant->is_incan = 2;
	ft_strcat(game->visu.cmd_out, "pic ");
	ft_strcat(game->visu.cmd_out, ft_itoa(trant->x));
	ft_strcat(game->visu.cmd_out, " ");
	ft_strcat(game->visu.cmd_out, ft_itoa(trant->y));
	ft_strcat(game->visu.cmd_out, " ");
	ft_strcat(game->visu.cmd_out, ft_itoa(trant->level + 1));
	ft_strcat(game->visu.cmd_out, " ");
	ft_strcat(game->visu.cmd_out, ft_itoa(trant->sock));
	ft_strcat(trant->cmd_out, "incantation en cours\nniveau actuel : ");
	ft_strcat(trant->cmd_out, ft_itoa(lvl));
	ft_strcat(trant->cmd_out, "\n");
}

void		ft_incan(t_data *game, t_trant *trant, int nb, int lvl)
{
	t_list_trant	*tra_lst;
	t_trant			*tra;

	ft_pic(game, trant, lvl);
	nb--;
	tra_lst = game->map[trant->x][trant->y]->list_player;
	while (tra_lst && nb)
	{
		tra = (tra_lst->player);
		if (tra->sock != trant->sock && tra->level == 2
				&& !ft_strcmp(tra->team, trant->team) && !trant->is_incan)
		{
			nb--;
			tra->is_incan = 1;
			ft_strcat(game->visu.cmd_out, " ");
			ft_strcat(game->visu.cmd_out, ft_itoa(tra->sock));
			gettimeofday(&tra->time, NULL);
			ft_strcat(tra->cmd_out, "incantation en cours\nniveau actuel : ");
			ft_strcat(tra->cmd_out, ft_itoa(lvl));
			ft_strcat(tra->cmd_out, "\n");
		}
		tra_lst = tra_lst->next;
	}
	ft_strcat(game->visu.cmd_out, "\n");
}

int			sv_incant_lvl_one(t_data *game, t_trant *trant)
{
	if (!game->map[trant->x][trant->y]->linemate)
		return (0);
	game->map[trant->x][trant->y]->linemate--;
	ft_place_linemate(game, game->length, game->width, 1);
	trant->is_incan = 2;
	ft_strcat(game->visu.cmd_out, "pic ");
	ft_strcat(game->visu.cmd_out, ft_itoa(trant->x));
	ft_strcat(game->visu.cmd_out, " ");
	ft_strcat(game->visu.cmd_out, ft_itoa(trant->y));
	ft_strcat(game->visu.cmd_out, " ");
	ft_strcat(game->visu.cmd_out, ft_itoa(trant->level + 1));
	ft_strcat(game->visu.cmd_out, " ");
	ft_strcat(game->visu.cmd_out, ft_itoa(trant->sock));
	ft_strcat(game->visu.cmd_out, "\n");
	ft_strcat(trant->cmd_out, "incantation en cours\nniveau actuel : 2\n");
	return (1);
}

int			sv_incant_lvl_two(t_data *game, t_trant *trant)
{
	if (!game->map[trant->x][trant->y]->linemate)
		return (0);
	if (!game->map[trant->x][trant->y]->deraumere)
		return (0);
	if (!game->map[trant->x][trant->y]->sibur)
		return (0);
	if (!sv_nb_player(game, trant))
		return (0);
	game->map[trant->x][trant->y]->linemate--;
	game->map[trant->x][trant->y]->deraumere--;
	game->map[trant->x][trant->y]->sibur--;
	ft_place_linemate(game, game->length, game->width, 1);
	ft_place_deraumere(game, game->length, game->width, 1);
	ft_place_sibur(game, game->length, game->width, 1);
	ft_incan(game, trant, 2, 3);
	return (1);
}
