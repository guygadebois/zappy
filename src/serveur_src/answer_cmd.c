/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   answer_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcouly <dcouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/20 16:07:06 by dcouly            #+#    #+#             */
/*   Updated: 2014/06/20 17:52:47 by dcouly           ###   ########.fr       */
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
	else
		ft_strcpy(trant->cmd_out, "ko\n");
}
