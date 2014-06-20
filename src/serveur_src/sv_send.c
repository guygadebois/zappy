/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sv_send.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcouly <dcouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 19:18:50 by dcouly            #+#    #+#             */
/*   Updated: 2014/06/20 16:42:45 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netdb.h>
#include <stdio.h>
#include <unistd.h>
#include "types.h"
#include "server.h"
#include "libft.h"

static int	sv_timer(t_trant *trant)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	if (time.tv_sec > trant->time.tv_sec
		|| (time.tv_sec == trant->time.tv_sec
			&& time.tv_usec >= trant->time.tv_usec))
		return (1);
	return (0);
}

void		sv_send(t_data *game, int sock)
{
	t_trant	*trant;

	if (sock != game->fd_visu)
	{
		trant = sv_getclientbysock(game, sock);
		if (trant->send && sv_timer(trant))
		{
			sv_answer_cmd(game, trant);
			send(sock, trant->cmd_out, ft_strlen(trant->cmd_out), 0);
			ft_bzero(trant->cmd_out, WORK_BUFSIZE);
			trant->send = 0;
//			ft_strcat(game->visu.cmd_out, "ok\n");
		}
	}
	else
	{
		send(sock, game->visu.cmd_out, ft_strlen(game->visu.cmd_out), 0);
		ft_bzero(game->visu.cmd_out, BUF_VISU);
	}
}
