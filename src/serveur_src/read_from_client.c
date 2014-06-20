/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_client.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcouly <dcouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 17:42:35 by dcouly            #+#    #+#             */
/*   Updated: 2014/06/19 16:33:36 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/select.h>
#include <sys/socket.h>
#include "common.h"
#include "server.h"

int			sv_read_from_client(t_data *game, int cs, fd_set *master)
{
	int		rd_oct;
	char	buf[BUFSIZE];

	if ((rd_oct = recv(cs, buf, BUFSIZE - 1, 0)) <= 0)
	{
		if (rd_oct == 0)
			printf("Connection closed by client on socket\n");
		else
			err_function("recv");
		if (game->fd_visu == cs)
			game->fd_visu = -1;
		close(cs);
		FD_CLR(cs, master);
	}
	else
	{
		buf[rd_oct] = 0;
		printf("%s\n", buf);
		if (cs == game->fd_visu)
			sv_cmd_visu(game, buf, rd_oct);
		else
			append_in_workbuf(game, sv_getclientbysock(game, cs), buf, rd_oct);
	}
	return (1);
}

