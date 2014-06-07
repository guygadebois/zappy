/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcouly <dcouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 16:44:18 by dcouly            #+#    #+#             */
/*   Updated: 2014/06/07 18:21:06 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/select.h>
#include <unistd.h>
#include "server.h"
#include "types.h"

int	sv_loop(int sock)
{
	t_fds	fds;
	int		fd_max;
	t_data	game;

	game.trant = NULL;
	game.sock = sock;
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
