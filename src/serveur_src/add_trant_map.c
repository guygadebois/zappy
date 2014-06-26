/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_trant_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcouly <dcouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/20 17:05:46 by dcouly            #+#    #+#             */
/*   Updated: 2014/06/26 13:52:29 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "types.h"
#include "server.h"
#include "libft.h"

void	add_trant_map(t_area ***map, t_trant *trant)
{
	t_list_trant	*lst;
	t_list_trant	*tmp;

	lst = map[trant->x][trant->y]->list_player;
	if (lst == NULL)
	{
		lst = (t_list_trant*)malloc(sizeof(t_list_trant));
		lst->player = trant;
		lst->next = NULL;
		map[trant->x][trant->y]->list_player = lst;
		return ;
	}
	tmp = (t_list_trant*)malloc(sizeof(t_list_trant));
	tmp->player = trant;
	tmp->next = NULL;
	while (lst->next)
		lst = lst->next;
	lst->next = tmp;
}
