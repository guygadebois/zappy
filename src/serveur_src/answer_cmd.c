/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   answer_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcouly <dcouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/20 16:07:06 by dcouly            #+#    #+#             */
/*   Updated: 2014/06/20 19:29:33 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
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
	else
		ft_strcpy(trant->cmd_out, "ko\n");
}
