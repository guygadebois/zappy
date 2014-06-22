/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_trant.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcouly <dcouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/22 18:28:00 by dcouly            #+#    #+#             */
/*   Updated: 2014/06/22 20:48:54 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "server.h"
#include "types.h"

void		sv_o_client_free(t_trant **trant)
{
	if (trant && *trant)
	{
		free((*trant)->team);
		(*trant)->team = NULL;
		free(*trant);
		*trant = NULL;
	}
}

int			sv_del_trant(t_data *data, int cs)
{
	t_list	*l;
	int		index;

	index = 0;
	l = data->trant;
	while (l)
	{
		if (((t_trant*)l->content)->sock == cs)
		{
			sv_o_client_free((t_trant**)&(l->content));
			ft_lst_remove_elem(&(data->trant), index);
			return (1);
		}
		index++;
		l = l->next;
	}
	return (err_function("sv_remove_client"));
}
