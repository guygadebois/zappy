/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_visu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcouly <dcouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/09 18:31:03 by dcouly            #+#    #+#             */
/*   Updated: 2014/06/12 17:40:11 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netdb.h>
#include <stdlib.h>
#include <stdio.h>
#include "common.h"
#include "server.h"

void			ft_strstrcat(char cmd_out[BUF_VISU], char *cmd, int nb, ...)
{
	va_list		ap;
	char		*str;

	va_start(ap, nb);
	ft_strcat(cmd_out, cmd);
	while (nb-- > 0)
	{
		str = ft_itoa(va_arg(ap, int));
		ft_strcat(cmd_out, " ");
		ft_strcat(cmd_out, str);
		free(str);
	}
	ft_strcat(cmd_out, "\n");
	va_end(ap);
}

static void		sv_map(t_data *game)
{
	int	cnt2;
	int	cnt;

	cnt = -1;
	while (++cnt < game->length)
	{
		cnt2 = -1;
		while (++cnt2 < game->width)
		{
			ft_strstrcat(game->visu.cmd_out, "bct", 9, cnt, cnt2,\
			game->map[cnt][cnt2]->food, \
			game->map[cnt][cnt2]->linemate, game->map[cnt][cnt2]->deraumere,\
			game->map[cnt][cnt2]->sibur, game->map[cnt][cnt2]->mendiane,\
			game->map[cnt][cnt2]->phiras, game->map[cnt][cnt2]->thystame);
		}
	}
}

void			sv_send_visu(t_data *game)
{
	ft_strstrcat(game->visu.cmd_out, "msz", 2, game->length, game->width);
	ft_strstrcat(game->visu.cmd_out, "sgt", 1, game->time);
	sv_map(game);
}
