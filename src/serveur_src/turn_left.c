/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/18 10:35:20 by bjacob            #+#    #+#             */
/*   Updated: 2014/06/21 16:05:58 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "types.h"
#include "libft.h"
#include "server.h"

void	ft_turn_left(t_trant *trant, t_data *game)
{
	trant->direct--;
	if (trant->direct == 0)
		trant->direct = 4;
	ft_strcat(trant->cmd_out, "ok\n");
	ft_strstrcat(game->visu.cmd_out, "ppo", 4, trant->sock, trant->x,
		trant->y, trant->direct);
}
