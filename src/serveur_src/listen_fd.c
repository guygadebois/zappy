/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listen_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcouly <dcouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 17:07:17 by dcouly            #+#    #+#             */
/*   Updated: 2014/06/26 11:08:23 by dcouly           ###   ########.fr       */
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
	ft_putendl("New connec");
	return (cs);
}

static int	is_team(char *name, t_data *game)
{
	t_list	*team;

	team = game->team;
	while (team)
	{
		if (!ft_strcmp(name, ((char *)team->content)))
			return (1);
		team = team->next;
	}
	ft_putendl("Wrong team name");
	return (0);
}

int			sv_listen_fd(t_data *game, int *fdmax, t_fds *fds)
{
	int		i;
	int		cs;
	char	buf[1024];
	int		nb;
	char	b[1024];

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
				ft_sendall(cs, "BIENVENUE\n", 10);
				nb = recv(cs, buf, 1023, 0);
				buf[nb] = 0;
				if (ft_strcmp("GRAPHIC\n", buf))
				{
					buf[nb - 1] = 0;
					if (is_team(buf, game))
					{
						sv_insert_trant(game, cs, buf);
						ft_strcat(b, ft_itoa(game->arg->nbmax));
						ft_strcat(b, "\n");
						ft_strcat(b, ft_itoa(game->length));
						ft_strcat(b, " ");
						ft_strcat(b, ft_itoa(game->width));
						ft_strcat(b, "\n");
						ft_sendall(cs, b, ft_strlen(b));
					}
					else
					{
						ft_sendall(cs, "mort\n", 5);
						close(cs);
						FD_CLR(cs, &(fds->master));
					}
				}
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
