/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcouly <dcouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 16:44:18 by dcouly            #+#    #+#             */
/*   Updated: 2014/06/23 17:56:58 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/select.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include "server.h"
#include "types.h"
#include "get_arg.h"
#include "map.h"

static int sv_diff_time(struct timeval t1, struct timeval t2, int t)
{
	struct timeval	res;
	float			diff;
	float			tmp;

	res.tv_sec = t2.tv_sec - t1.tv_sec;
	if (t2.tv_usec < t1.tv_usec)
	{
		res.tv_sec--;
		res.tv_usec = 1000000 + t2.tv_usec - t1.tv_usec;
	}
	else
		res.tv_usec = t2.tv_usec - t1.tv_usec;
	tmp = res.tv_usec;
	diff = res.tv_sec;
	diff += tmp / 1000000;
	if (diff * t >= 126.0)
		return (1);
	return (0);
}

static void	sv_loose_life(t_data *game, t_fds *fd)
{
	t_list			*lst;
	struct timeval	time;
	struct timeval	time_trant;
	fd_set			fd_dead;

	gettimeofday(&time, NULL);
	lst = game->trant;
	while (lst)
	{
		time_trant = ((t_trant*)(lst->content))->t_life;
		if (sv_diff_time(time_trant, time, game->time))
		{
			((t_trant*)(lst->content))->t_life = time;
			((t_trant*)(lst->content))->life--;
			if (((t_trant*)(lst->content))->life == 0)
			{
				ft_strcpy(game->visu.cmd_out, "pdi ");
				ft_strcpy(game->visu.cmd_out,
						ft_itoa(((t_trant*)lst->content)->sock));
				ft_strcpy(game->visu.cmd_out, "\n");
				FD_ZERO(&fd_dead);
				FD_SET(((t_trant*)lst->content)->sock, &fd_dead);
				while (select((((t_trant*)lst->content)->sock) + 1, NULL,
						&fd_dead, NULL, NULL) == 0)
					FD_SET(((t_trant*)lst->content)->sock, &fd_dead);
				ft_sendall(((t_trant*)lst->content)->sock, "mort\n", 5);
				FD_CLR(((t_trant*)lst->content)->sock, &fd->master);
				sv_del_trant(game, ((t_trant*)lst->content)->sock);
				lst = game->trant;
			}
			else
				lst = lst->next;
		}
		else
			lst = lst->next;
	}
}

int			sv_loop(int sock, t_arg *arg)
{
	t_fds	fds;
	int		fd_max;
	t_data	game;

	game.trant = NULL;
	game.length = arg->width;
	game.width = arg->height;
	game.time = arg->t;
	game.map = ft_create_map(game.length, game.width, 15);
	game.sock = sock;
	game.nbmax = arg->nbmax;
	game.fd_max = sock;
	game.team = arg->team;
	game.fd_visu = -1;
	game.lvl_max = 1;
	fd_max = sock;
	FD_ZERO(&(fds.master));
	FD_ZERO(&(fds.read));
	FD_ZERO(&(fds.write));
	FD_SET(sock, &(fds.master));
	while (game.lvl_max != 8)
	{
		sv_loose_life(&game, &fds);
		fds.read = fds.master;
		fds.write = fds.master;
		if (select(game.fd_max + 1, &(fds.read), &(fds.write), NULL, NULL) == -1)
			return (err_function("select"));
		sv_listen_fd(&game, &fd_max, &fds);
	}
	return (1);
}
