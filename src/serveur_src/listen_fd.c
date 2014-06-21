/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listen_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcouly <dcouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 17:07:17 by dcouly            #+#    #+#             */
/*   Updated: 2014/06/21 20:04:52 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <netdb.h>
#include <stdio.h>
#include "types.h"
#include "server.h"

static int	sv_new_connection(int sock, int *fdmax, fd_set *master)
{
	int					cs;
	unsigned int		cslen;
	struct sockaddr_in	csin;

	cslen = sizeof(csin);
	if ((cs = accept(sock, (struct sockaddr *)&csin, &cslen)) == -1)
	{
		err_function("accept");
		return (-1);
	}
	FD_SET(cs, master);
	if (cs > *fdmax)
		*fdmax = cs;
	printf("New connec\n");
	return (cs);
}

int			sv_listen_fd(t_data *game, int *fdmax, t_fds *fds)
{
	int		i;
	int		cs;
	char	buf[1024];
	int		nb;

	*fdmax = *fdmax + 0;
	i = 0;
	while (i <= game->fd_max)
	{
		if (FD_ISSET(i, &(fds->write)))
			sv_send(game, i);
		if (FD_ISSET(i, &(fds->read)))
		{
			if ((i == game->sock) && (cs = sv_new_connection(game->sock,\
					&game->fd_max, &(fds->master))) != -1)
			{
				send(cs, "BIENVENUE\n", 10, 0);
				nb = recv(cs, buf, 1023, 0);
				buf[nb] = 0;
				if (ft_strcmp("GRAPHIC\n", buf))
					sv_insert_trant(game, cs, buf);
				else
				{
					game->fd_visu = cs;
					game->visu.sock = cs;
					ft_bzero(game->visu.cmd_in, WORK_BUFSIZE);
					ft_bzero(game->visu.cmd_out, BUF_VISU);
					sv_send_visu(game);
				}
			}
			else
				sv_read_from_client(game, i, &(fds->master));
		}
		i++;
	}
	return (1);
}
