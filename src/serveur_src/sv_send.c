/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sv_send.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcouly <dcouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 19:18:50 by dcouly            #+#    #+#             */
/*   Updated: 2014/06/10 16:34:21 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netdb.h>
#include <stdio.h>
#include "types.h"
#include "server.h"
#include "libft.h"

void	sv_send(t_data *game, int sock)
{
	t_trant	*trant;

	if (sock != game->fd_visu)
	{
		trant = sv_getclientbysock(game, sock);
		if (trant->cmd_out[0])
		{
			send(sock, trant->cmd_out, ft_strlen(trant->cmd_out), 0);
			ft_bzero(trant->cmd_out, WORK_BUFSIZE);
		}
	}
	else
	{
		send(sock, game->visu.cmd_out, ft_strlen(game->visu.cmd_out), 0);
		ft_bzero(game->visu.cmd_out, BUF_VISU);
	}
}
