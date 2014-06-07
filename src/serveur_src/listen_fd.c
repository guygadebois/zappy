/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listen_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcouly <dcouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 17:07:17 by dcouly            #+#    #+#             */
/*   Updated: 2014/06/07 19:17:15 by dcouly           ###   ########.fr       */
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

	i = 0;
	while (i <= *fdmax)
	{
		if (FD_ISSET(i, &(fds->read)))
		{
			if (i == game->sock)
			{
				if ((cs = sv_new_connection(game->sock, fdmax, &(fds->master))) \
					   	!= -1)
					sv_insert_trant(game, cs);
			}
			else
				sv_read_from_client(game, i, &(fds->master));
		}
		if (FD_ISSET(i, &(fds->write)))
			sv_send(game, i);
		i++;
	}
	return (1);
}
