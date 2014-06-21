/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcouly <dcouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 16:44:18 by dcouly            #+#    #+#             */
/*   Updated: 2014/06/21 20:13:44 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/select.h>
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

static void	sv_loose_life(t_data game)
{
	t_list			*lst;
	struct timeval	time;
	struct timeval	time_trant;

	gettimeofday(&time, NULL);
	lst = game.trant;
	while (lst)
	{
		time_trant = ((t_trant*)(lst->content))->t_life;
		if (sv_diff_time(time_trant, time, game.time))
		{
			((t_trant*)(lst->content))->t_life = time;
			((t_trant*)(lst->content))->life--;
/*			if (((t_trant*)(lst->content))->life == 0)
			{	printf("DIE\n");
				sleep(100);
			}
*/		}
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
	game.map = ft_create_map(game.length, game.width, 50);
	game.sock = sock;
	game.nbmax = arg->nbmax;
	game.fd_max = sock;
	game.team = arg->team;
	game.fd_visu = -1;
	fd_max = sock;
	FD_ZERO(&(fds.master));
	FD_ZERO(&(fds.read));
	FD_ZERO(&(fds.write));
	FD_SET(sock, &(fds.master));
	while (1)
	{
		sv_loose_life(game);
		fds.read = fds.master;
		fds.write = fds.master;
		if (select(game.fd_max + 1, &(fds.read), &(fds.write), NULL, NULL) == -1)
			return (err_function("select"));
		sv_listen_fd(&game, &fd_max, &fds);
	}
}
