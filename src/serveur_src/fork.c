/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcouly <dcouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 09:28:03 by dcouly            #+#    #+#             */
/*   Updated: 2014/06/26 13:14:59 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "server.h"
#include "types.h"
#include "map.h"


int         sv_o_oeuf_init(t_trant **trant, int sock, t_trant *tran,
		t_data *game)
{
	static int	num = 1;
	
	if (!(*trant = (t_trant *)malloc(sizeof(t_trant))))
		return (err_malloc());
	(*trant)->sock = sock;
	(*trant)->team = NULL;
	ft_bzero((*trant)->cmd_in, WORK_BUFSIZE);
	ft_bzero((*trant)->cmd_out, WORK_BUFSIZE);
	(*trant)->x = tran->x;
	(*trant)->y = tran->y;
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
	(*trant)->is_oeuf = 1;
	(*trant)->nb_oeuf = num;
	(*trant)->current_cmd = ft_strdup("\n");
	num++;
	(*trant)->is_incan = 0;
	(*trant)->send = 0;
	gettimeofday(&(*trant)->t_life, NULL);
	(*trant)->team = ft_strdup(tran->team);
	add_trant_map(game->map, *trant);
//	sv_new_trant_to_visu(game, *trant);
	return (1);
}

void	ft_fork(t_data *game, t_trant *trant)
{
	t_trant 	*oeuf;
	char		buf[1024];

	ft_strcat(buf, trant->team);	
	sv_o_oeuf_init(&oeuf, trant->sock, trant, game);
	gettimeofday(&oeuf->time, NULL);
	ft_lstpushback(&(game->trant), oeuf, 0);
	ft_strcat(trant->cmd_out, "ok\n");	
}
