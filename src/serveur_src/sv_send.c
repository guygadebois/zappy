/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sv_send.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcouly <dcouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 19:18:50 by dcouly            #+#    #+#             */
/*   Updated: 2014/06/26 14:31:02 by dcouly           ###   ########.fr       */
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

void		send_a_oeuf(t_trant *trant, t_data *game)
{
	trant->is_oeuf = 0;
	ft_strcat(trant->cmd_out, "ok\n");
	ft_strcat(game->visu.cmd_out, "eht #e\n");
	ft_strcat(game->visu.cmd_out, ft_itoa(trant->nb_oeuf));
	ft_strcat(game->visu.cmd_out, "\n");
}

void		ft_incan_end(t_trant *trant, t_data *game)
{
	if (trant->is_incan == 2)
	{
		ft_strcat(game->visu.cmd_out, "pie ");
		ft_strcat(game->visu.cmd_out, ft_itoa(trant->x));
		ft_strcat(game->visu.cmd_out, " ");
		ft_strcat(game->visu.cmd_out, ft_itoa(trant->y));
		ft_strcat(game->visu.cmd_out, " 1\n");
	}
	trant->level++;
	trant->is_incan = 0;
}

void		sv_ans(t_data *game, t_trant *trant, int sock)
{
	sv_answer_cmd(game, trant);
	ft_sendall(sock, trant->cmd_out, ft_strlen(trant->cmd_out));
	ft_bzero(trant->cmd_out, WORK_BUFSIZE);
	trant->send = 0;
	trant->fail = 0;
}

void		sv_send(t_data *game, int sock)
{
	t_trant	*trant;

	if (sock != game->fd_visu)
	{
		trant = sv_getclientbysock(game, sock);
		if (trant == NULL)
			return ;
		if ((trant->send && sv_timer(trant)) || trant->fail)
		{
			if (trant->is_oeuf)
			{
				send_a_oeuf(trant, game);
				return ;
			}
			sv_ans(game, trant, sock);
			if (trant->is_incan)
				ft_incan_end(trant, game);
		}
	}
	else
	{
		ft_sendall(sock, game->visu.cmd_out, ft_strlen(game->visu.cmd_out));
		ft_bzero(game->visu.cmd_out, BUF_VISU);
	}
}
