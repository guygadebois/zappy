/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   answer_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcouly <dcouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/20 16:07:06 by dcouly            #+#    #+#             */
/*   Updated: 2014/06/22 18:22:35 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "types.h"
#include "map.h"
#include "server.h" 

void	sv_answer_cmd(t_data *game, t_trant *trant)
{
	printf("trant -> %d,  map -> %d\n", trant->lin, game->map[trant->x][trant->y]->linemate);
	if (!ft_strcmp(trant->current_cmd, "avance"))
		ft_move_forward(game, trant, game->map);
	else if (!ft_strcmp(trant->current_cmd, "droite"))
		ft_turn_right(trant, game);
	else if (!ft_strcmp(trant->current_cmd, "gauche"))
		ft_turn_left(trant, game);
	else if (!ft_strncmp(trant->current_cmd, "prend", 5))
		ft_take_obj(game->map, trant, &trant->current_cmd[6], game);
	else if (!ft_strncmp(trant->current_cmd, "pose", 4))
		ft_drop_obj(game->map, trant, &trant->current_cmd[5], game);
	else if (!ft_strcmp(trant->current_cmd, "inventaire"))
		ft_get_inventory(trant);
	else if (!ft_strncmp(trant->current_cmd, "broadcaster", 11))
		broadcast(game, &trant->current_cmd[12], trant->sock);
/*	else if (!ft_strcmp(trant->current_cmd, "gauche"))
	else if (!ft_strcmp(trant->current_cmd, "gauche"))
	else if (!ft_strcmp(trant->current_cmd, "gauche"))
*/	else
		ft_strcat(trant->cmd_out, "ko\n");
	printf("trant -> %d,  map -> %d\n", trant->lin, game->map[trant->x][trant->y]->linemate);
}
