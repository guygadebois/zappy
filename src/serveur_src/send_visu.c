/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_visu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcouly <dcouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/09 18:31:03 by dcouly            #+#    #+#             */
/*   Updated: 2014/06/26 13:00:26 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netdb.h>
#include <stdlib.h>
#include <stdio.h>
#include "common.h"
#include "server.h"

void			ft_strstrcat(char cmd_out[BUF_VISU], char *cmd, int nb, ...)
{
	va_list		ap;
	char		*str;

	va_start(ap, nb);
	ft_strcat(cmd_out, cmd);
	while (nb-- > 0)
	{
		str = ft_itoa(va_arg(ap, int));
		ft_strcat(cmd_out, " ");
		ft_strcat(cmd_out, str);
		free(str);
	}
	ft_strcat(cmd_out, "\n");
	va_end(ap);
}

static void		sv_map(t_data *game)
{
	int		cnt2;
	int		cnt;
	fd_set	write_fd;

	cnt = -1;
	while (++cnt < game->length)
	{
		cnt2 = -1;
		while (++cnt2 < game->width)
		{
			FD_ZERO(&write_fd);
			FD_SET(game->fd_visu, &write_fd);
			ft_strstrcat(game->visu.cmd_out, "bct", 9, cnt, cnt2,\
			game->map[cnt][cnt2]->food, \
			game->map[cnt][cnt2]->linemate, game->map[cnt][cnt2]->deraumere,\
			game->map[cnt][cnt2]->sibur, game->map[cnt][cnt2]->mendiane,\
			game->map[cnt][cnt2]->phiras, game->map[cnt][cnt2]->thystame);
			select(game->fd_visu + 1, NULL, &write_fd, NULL, NULL);
			if (FD_ISSET(game->fd_visu, &write_fd))	
				sv_send(game, game->fd_visu);
		}
	}
}

void			send_pic(t_data *game)
{
	t_list	*lst;

	lst = game->trant;
	while (lst)
	{
		if (((t_trant*)lst->content)->is_incan == 2)
		{
			ft_strcat(game->visu.cmd_out, "pic ");
			ft_strcat(game->visu.cmd_out, ft_itoa(((t_trant*)lst->content)->x));
			ft_strcat(game->visu.cmd_out, " ");
			ft_strcat(game->visu.cmd_out, ft_itoa(((t_trant*)lst->content)->y));
			ft_strcat(game->visu.cmd_out, " ");
			ft_strcat(game->visu.cmd_out, ft_itoa(((t_trant*)lst->content)->level + 1));
			ft_strcat(game->visu.cmd_out, " ");
			ft_strcat(game->visu.cmd_out, ft_itoa(((t_trant*)lst->content)->sock));
			ft_strcat(game->visu.cmd_out, "\n");
		}	
		lst = lst->next;
	}
}

void			send_oeuf(t_data *game)
{
	t_list	*lst;

	lst = game->trant;
	while (lst)
	{
		if (((t_trant*)lst->content)->is_oeuf)
		{
			ft_strcat(game->visu.cmd_out, "enw ");
			ft_strcat(game->visu.cmd_out, ft_itoa(((t_trant*)lst->content)->nb_oeuf));
			ft_strcat(game->visu.cmd_out, " ");
			ft_strcat(game->visu.cmd_out, ft_itoa(((t_trant*)lst->content)->sock));
			ft_strcat(game->visu.cmd_out, " ");
			ft_strcat(game->visu.cmd_out, ft_itoa(((t_trant*)lst->content)->x));
			ft_strcat(game->visu.cmd_out, " ");
			ft_strcat(game->visu.cmd_out, ft_itoa(((t_trant*)lst->content)->y));
			ft_strcat(game->visu.cmd_out, "\n");
		}	
		lst = lst->next;
	}	
}

void			sv_send_visu(t_data *game)
{
	t_list	*lst;

	ft_strstrcat(game->visu.cmd_out, "msz", 2, game->length, game->width);
	ft_strstrcat(game->visu.cmd_out, "sgt", 1, game->time);
	sv_map(game);
	lst = game->team;
	while (lst)
	{
		ft_strcat(game->visu.cmd_out, "tna ");
		ft_strcat(game->visu.cmd_out, (char*)lst->content);
		ft_strcat(game->visu.cmd_out, "\n");
		lst = lst->next;
	}
	lst = game->trant;
	while (lst)
	{
		if (((t_trant*)lst->content)->is_oeuf == 0)
		sv_new_trant_to_visu(game, (t_trant*)lst->content);
		lst = lst->next;
	}
	send_pic(game);
	send_oeuf(game);
}
