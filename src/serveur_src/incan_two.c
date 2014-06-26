/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   incan_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcouly <dcouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 14:59:36 by dcouly            #+#    #+#             */
/*   Updated: 2014/06/26 15:01:58 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "types.h"
#include "server.h"
#include "map.h"
#include "libft.h"

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
