/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcouly <dcouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 16:44:18 by dcouly            #+#    #+#             */
/*   Updated: 2014/06/20 18:16:37 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/select.h>
#include <unistd.h>
#include <stdio.h>
#include "server.h"
#include "types.h"
#include "get_arg.h"
#include "map.h"

int	sv_loop(int sock, t_arg *arg)
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
	game.team = arg->team;
	game.fd_visu = -1;
	fd_max = sock;
	FD_ZERO(&(fds.master));
	FD_ZERO(&(fds.read));
	FD_ZERO(&(fds.write));
	FD_SET(sock, &(fds.master));
	while (1)
	{
		fds.read = fds.master;
		fds.write = fds.master;
		if (select(fd_max + 1, &(fds.read), &(fds.write), NULL, NULL) == -1)
			return (err_function("select"));
		sv_listen_fd(&game, &fd_max, &fds);
	}
}
