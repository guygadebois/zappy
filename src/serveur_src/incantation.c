/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   incantation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcouly <dcouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 13:45:48 by dcouly            #+#    #+#             */
/*   Updated: 2014/06/26 15:02:29 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "types.h"
#include "server.h"
#include "map.h"
#include "libft.h"

int			sv_incant_lvl_four(t_data *game, t_trant *trant)
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

int			sv_incant_lvl_five(t_data *game, t_trant *trant)
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

int			sv_incant_lvl_six(t_data *game, t_trant *trant)
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

int			sv_incant_lvl_seven(t_data *game, t_trant *trant)
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
