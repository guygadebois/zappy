/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_trant.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcouly <dcouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 18:24:06 by dcouly            #+#    #+#             */
/*   Updated: 2014/06/26 13:16:35 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "types.h"
#include "server.h"
#include "libft.h"

void	sv_new_trant_to_visu(t_data *game, t_trant *trant)
{
	if (game->fd_visu > 0)
	{
		ft_strcat(game->visu.cmd_out, "pnw ");
		ft_strcat(game->visu.cmd_out, ft_itoa(trant->sock));
		ft_strcat(game->visu.cmd_out, " ");
		ft_strcat(game->visu.cmd_out, ft_itoa(trant->x));
		ft_strcat(game->visu.cmd_out, " ");
		ft_strcat(game->visu.cmd_out, ft_itoa(trant->y));
		ft_strcat(game->visu.cmd_out, " ");
		ft_strcat(game->visu.cmd_out, ft_itoa(trant->direct));
		ft_strcat(game->visu.cmd_out, " ");
		ft_strcat(game->visu.cmd_out, ft_itoa(trant->level));
		ft_strcat(game->visu.cmd_out, " ");
		ft_strcat(game->visu.cmd_out, trant->team);
		ft_strcat(game->visu.cmd_out, "\n");
	}
}

int			sv_o_trant_init(t_trant **trant, int sock, char buf[1024],
							t_data *game)
{
	if (!(*trant = (t_trant *)malloc(sizeof(t_trant))))
		return (err_malloc());
	(*trant)->sock = sock;
	(*trant)->team = NULL;
	ft_bzero((*trant)->cmd_in, WORK_BUFSIZE);
	ft_bzero((*trant)->cmd_out, WORK_BUFSIZE);
	(*trant)->x = rand() % game->length;
	(*trant)->y = rand() % game->width;
	(*trant)->level = 1;
	(*trant)->life = 10;
	(*trant)->direct = rand() % 4 + 1;
	(*trant)->lin = 0;
	(*trant)->fail = 0;
	(*trant)->der = 0;
	(*trant)->sib = 0;
	(*trant)->men = 0;
	(*trant)->phi = 0;
	(*trant)->thy = 0;
	(*trant)->is_oeuf = 0;
	(*trant)->nb_oeuf = 0;
	(*trant)->is_incan = 0;
	(*trant)->send = 0;
	gettimeofday(&(*trant)->t_life, NULL);
	(*trant)->team = ft_strdup(buf);
	(*trant)->current_cmd = NULL;
	add_trant_map(game->map, *trant);
	sv_new_trant_to_visu(game, *trant);
	return (1);
}

int			is_oeuf_dispo(t_data *game, int cs, char buf[1024])
{
	t_list	*tra;
	t_trant	*trant;

	tra = game->trant;
	while (tra)
	{
		trant = ((t_trant*)tra->content);
		if (trant->is_oeuf && !ft_strcmp(buf, trant->team))
		{
			trant->sock = cs;
			ft_strcat(game->visu.cmd_out, "ebo ");
			ft_strcat(game->visu.cmd_out, ft_itoa(trant->nb_oeuf));
			ft_strcat(game->visu.cmd_out, "\n");
			printf("Connecte a l'oeuf\n");
			return (1);
		}
		tra = tra->next;
	}
	return (0);
}

int			sv_insert_trant(t_data *game, int cs, char buf[1024])
{
	t_trant	*new_trant;

	if (is_oeuf_dispo(game, cs, buf))
		return (1);
	if (!sv_o_trant_init(&new_trant, cs, buf, game))
		return (0);
	if (!ft_lstpushback(&(game->trant), new_trant, 0))
		return (err_malloc());
	return (1);
}
