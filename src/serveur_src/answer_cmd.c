/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   answer_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcouly <dcouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/20 16:07:06 by dcouly            #+#    #+#             */
/*   Updated: 2014/06/26 15:46:32 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "map.h"
#include "server.h"

void	sv_answer_cmd(t_data *game, t_trant *trant)
{
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
	else if (!ft_strcmp(trant->current_cmd, "voir"))
		voir(game, trant);
	else if (!ft_strcmp(trant->current_cmd, "inventaire"))
		ft_get_inventory(trant);
	else if (!ft_strncmp(trant->current_cmd, "broadcast", 9))
		broadcast(game, &trant->current_cmd[10], trant->sock);
	else if (!ft_strcmp(trant->current_cmd, "expulse"))
		ft_kick(game->arg, game->map, trant);
	else if (!ft_strcmp(trant->current_cmd, "connect_nbr"))
		ft_connect_nbr(game->arg, game->trant, trant->team, trant);
	else if (!ft_strcmp(trant->current_cmd, "fork"))
		ft_fork(game, trant);
	else if (ft_strcmp(trant->current_cmd, "incantation"))
		ft_strcat(trant->cmd_out, "ko\n");
}
