/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   incantation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcouly <dcouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 13:45:48 by dcouly            #+#    #+#             */
/*   Updated: 2014/06/26 13:55:01 by bjacob           ###   ########.fr       */
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

void		ft_incan(t_data *game, t_trant *trant, int nb, int lvl)
{
	t_list_trant	*tra_lst;
	t_trant			*tra;

	trant->is_incan = 2;
	nb--;
	ft_strcat(game->visu.cmd_out, "pic ");
	ft_strcat(game->visu.cmd_out, ft_itoa(trant->x));
	ft_strcat(game->visu.cmd_out, " ");
	ft_strcat(game->visu.cmd_out, ft_itoa(trant->y));
	ft_strcat(game->visu.cmd_out, " ");
	ft_strcat(game->visu.cmd_out, ft_itoa(trant->level + 1));
	ft_strcat(game->visu.cmd_out, " ");
	ft_strcat(game->visu.cmd_out, ft_itoa(trant->sock));
	tra_lst = game->map[trant->x][trant->y]->list_player;
	ft_strcat(trant->cmd_out, "incantation en cours\nniveau actuel : ");
	ft_strcat(trant->cmd_out, ft_itoa(lvl));
	ft_strcat(trant->cmd_out, "\n");
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

int	sv_incant_lvl_one(t_data *game, t_trant *trant)
{
	printf("la\n");
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
	game->map[trant->x][trant->y]->linemate--;
	game->map[trant->x][trant->y]->deraumere--;
	game->map[trant->x][trant->y]->sibur--;
	ft_place_linemate(game, game->length, game->width, 1);
	ft_place_deraumere(game, game->length, game->width, 1);
	ft_place_sibur(game, game->length, game->width, 1);
	ft_incan(game, trant, 2, 3);
	return (1);
}

int	sv_incant_lvl_three(t_data *game, t_trant *trant)
{
	if (game->map[trant->x][trant->y]->linemate < 2)
		return (0);
	if (game->map[trant->x][trant->y]->phiras < 2)
		return (0);
	if (!game->map[trant->x][trant->y]->sibur)
		return (0);
	if (!sv_nb_player(game, trant))
		return (0);
	game->map[trant->x][trant->y]->linemate -= 2;
	game->map[trant->x][trant->y]->phiras -= 2;
	game->map[trant->x][trant->y]->sibur--;
	ft_place_linemate(game, game->length, game->width, 2);
	ft_place_phiras(game, game->length, game->width, 2);
	ft_place_sibur(game, game->length, game->width, 1);
	
	ft_incan(game, trant, 2, 4);
	return (1);
}

int	sv_incant_lvl_four(t_data *game, t_trant *trant)
{
	if (!game->map[trant->x][trant->y]->linemate)
		return (0);
	if (!game->map[trant->x][trant->y]->deraumere)
		return (0);
	if (!game->map[trant->x][trant->y]->phiras)
		return (0);
	if (game->map[trant->x][trant->y]->sibur < 2)
		return (0);
	if (sv_nb_player(game, trant) < 3)
		return (0);
	game->map[trant->x][trant->y]->linemate--;
	game->map[trant->x][trant->y]->deraumere--;
	game->map[trant->x][trant->y]->sibur -= 2;
	game->map[trant->x][trant->y]->phiras--;
	ft_place_linemate(game, game->length, game->width, 1);
	ft_place_deraumere(game, game->length, game->width, 1);
	ft_place_sibur(game, game->length, game->width, 2);
	ft_place_phiras(game, game->length, game->width, 1);
	ft_incan(game, trant, 4, 5);
	return (1);
}

int	sv_incant_lvl_five(t_data *game, t_trant *trant)
{
	if (game->map[trant->x][trant->y]->linemate < 1)
		return (0);
	if (game->map[trant->x][trant->y]->deraumere < 2)
		return (0);
	if (game->map[trant->x][trant->y]->sibur < 1)
		return (0);
	if (game->map[trant->x][trant->y]->mendiane < 3)
		return (0);
	if (sv_nb_player(game, trant) < 3)
		return (0);
	game->map[trant->x][trant->y]->linemate--;
	game->map[trant->x][trant->y]->deraumere -= 2;
	game->map[trant->x][trant->y]->sibur -= 1;
	game->map[trant->x][trant->y]->mendiane -= 3;
	ft_place_linemate(game, game->length, game->width, 1);
	ft_place_deraumere(game, game->length, game->width, 2);
	ft_place_sibur(game, game->length, game->width, 1);
	ft_place_mendiane(game, game->length, game->width, 3);
	ft_incan(game, trant, 4, 6);
	return (1);
}

int	sv_incant_lvl_six(t_data *game, t_trant *trant)
{
	if (game->map[trant->x][trant->y]->linemate < 1)
		return (0);
	if (game->map[trant->x][trant->y]->deraumere < 2)
		return (0);
	if (game->map[trant->x][trant->y]->sibur < 3)
		return (0);
	if (game->map[trant->x][trant->y]->phiras < 1)
		return (0);
	if (sv_nb_player(game, trant) < 5)
		return (0);
	game->map[trant->x][trant->y]->linemate--;
	game->map[trant->x][trant->y]->deraumere -= 2;
	game->map[trant->x][trant->y]->sibur -= 3;
	game->map[trant->x][trant->y]->phiras -= 1;
	ft_place_linemate(game, game->length, game->width, 1);
	ft_place_deraumere(game, game->length, game->width, 2);
	ft_place_sibur(game, game->length, game->width, 3);
	ft_place_phiras(game, game->length, game->width, 1);
	ft_incan(game, trant, 6, 7);
	return (1);
}

int	sv_incant_lvl_seven(t_data *game, t_trant *trant)
{
	if (game->map[trant->x][trant->y]->linemate < 2)
		return (0);
	if (game->map[trant->x][trant->y]->deraumere < 2)
		return (0);
	if (game->map[trant->x][trant->y]->sibur < 2)
		return (0);
	if (game->map[trant->x][trant->y]->mendiane < 2)
		return (0);
	if (game->map[trant->x][trant->y]->phiras < 2)
		return (0);
	if (game->map[trant->x][trant->y]->thystame < 1)
		return (0);
	if (sv_nb_player(game, trant) < 5)
		return (0);
	game->lvl_max = 8;
	ft_incan(game, trant, 6, 8);
	return (1);
}

void		sv_incantation(t_data *game, t_trant *trant)
{
	int opt;

	if (trant->level == 1)
		opt = sv_incant_lvl_one(game, trant);
	else if (trant->level == 2)
		opt = sv_incant_lvl_two(game, trant);
	else if (trant->level == 3)
		opt = sv_incant_lvl_three(game, trant);
	else if (trant->level == 4)
		opt = sv_incant_lvl_four(game, trant);
	else if (trant->level == 5)
		opt = sv_incant_lvl_five(game, trant);
	else if (trant->level == 6)
		opt = sv_incant_lvl_six(game, trant);
	else if (trant->level == 7)
		opt = sv_incant_lvl_seven(game, trant);
	if (opt == 0)
	{
		trant->fail = 1;
		trant->send = 1;
		ft_strcat(trant->cmd_out, "ko\n");
	}
}
