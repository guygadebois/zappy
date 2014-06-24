/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   incantation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcouly <dcouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 13:45:48 by dcouly            #+#    #+#             */
/*   Updated: 2014/06/24 17:43:36 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "map.h"
#include "libft.h"

int			sv_nb_player(t_data *game, t_trant *trant)
{
	int				nb;
	t_list_trant	*tra_lst;
	t_trant			*tra;

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

void		ft_incan(t_data *game, t_trant *trant, int lvl)
{
	t_list_trant	*tra_lst;
	t_trant			*tra;

	trant->is_incan = 1;

	tra_lst = game->map[trant->x][trant->y]->list_player;
	while (tra_lst && lvl)
	{
		tra = (tra_lst->player);
		if (tra->sock != trant->sock && trant->level == tra->level
				&& !ft_strcmp(tra->team, trant->team) && !trant->is_incan)
		{
			lvl--;

		}
		tra_lst = tra_lst->next;
	}	
}
#include <stdio.h>

int	sv_incant_lvl_one(t_data *game, t_trant *trant)
{
	if (!game->map[trant->x][trant->y]->linemate)
		return (0);
	trant->level++;
	trant->is_incan = 1;
	ft_strcat(trant->cmd_out, "ok\n");
	return (1);
}

int	sv_incant_lvl_two(t_data *game, t_trant *trant)
{
	if (!game->map[trant->x][trant->y]->linemate)
		return (0);
	if (!game->map[trant->x][trant->y]->deraumere)
		return (0);
	if (!game->map[trant->x][trant->y]->sibur)
		return (0);
	if (!sv_nb_player(game, trant))
		return (0);
	ft_incan(game, trant, 2);
	return (1);
}

void		sv_incantation(t_data *game, t_trant *trant)
{
	if (trant->level == 1)
		sv_incant_lvl_one(game, trant);
	else if (trant->level == 3)
		sv_incant_lvl_one(game, trant);
	else if (trant->level == 3)
		sv_incant_lvl_one(game, trant);
	else if (trant->level == 4)
		sv_incant_lvl_one(game, trant);
	else if (trant->level == 5)
		sv_incant_lvl_one(game, trant);
	else if (trant->level == 6)
		sv_incant_lvl_one(game, trant);
	else if (trant->level == 7)
		sv_incant_lvl_one(game, trant);
	else if (trant->level == 8)
		sv_incant_lvl_one(game, trant);
	else
		ft_strcat(trant->cmd_out, "ko\n");
}
