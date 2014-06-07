/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_trant.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcouly <dcouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 18:24:06 by dcouly            #+#    #+#             */
/*   Updated: 2014/06/07 18:44:52 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "types.h"
#include "server.h"
#include "libft.h"

static int	sv_o_trant_init(t_trant **trant, int sock)
{
	if (!(*trant = (t_trant *)malloc(sizeof(t_trant))))
		return (err_malloc());
	(*trant)->sock = sock;
	(*trant)->team = NULL;
	ft_bzero((*trant)->cmd_in, WORK_BUFSIZE);
	ft_bzero((*trant)->cmd_out, WORK_BUFSIZE);
	(*trant)->x = rand();
	(*trant)->y = rand();
	(*trant)->level = 1;
	(*trant)->life = 126;
	(*trant)->lin = 0;
	(*trant)->der = 0;
	(*trant)->sib = 0;
	(*trant)->men = 0;
	(*trant)->phi = 0;
	(*trant)->thy = 0;
	return (1);
}

int			sv_insert_trant(t_data *game, int cs)
{
	t_trant	*new_trant;

	if (!sv_o_trant_init(&new_trant, cs))
		return (0);
	if (!ft_lstpushback(&game->trant, new_trant, 0))
		return (err_malloc());
	return (1);
}
