/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcouly <dcouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 16:44:18 by dcouly            #+#    #+#             */
/*   Updated: 2014/06/17 16:48:36 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/select.h>
#include <unistd.h>
#include <stdio.h>
#include "server.h"
#include "types.h"
#include "map.h"

int	sv_loop(int sock)
{
	t_fds	fds;
	int		fd_max;
	t_data	game;

	game.trant = NULL;
	game.length = 10;
	game.width = 10;
	game.time = 10;
	game.map = ft_create_map(10, 10, 50);
	game.sock = sock;
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
