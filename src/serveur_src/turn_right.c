/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/18 09:58:21 by bjacob            #+#    #+#             */
/*   Updated: 2014/06/20 19:23:40 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "types.h"
#include "libft.h"
#include "server.h"

void	ft_turn_right(t_trant *trant, t_data *game)
{
	trant->direct %= 4;
	trant->direct++;
	ft_strcpy(trant->cmd_out, "ok\n");
	ft_strstrcat(game->visu.cmd_out, "ppo", 4, trant->sock, trant->x,
		trant->y, trant->direct);
}
