/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 16:00:36 by glourdel          #+#    #+#             */
/*   Updated: 2014/01/28 16:43:55 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		ft_dlst_remove(t_dlist **begin_list, t_dlist *to_remove)
{
	t_dlist	*prev;
	t_dlist	*next;

	if (begin_list && *begin_list && to_remove)
	{
		prev = to_remove->prev;
		next = to_remove->next;
		if (*begin_list == to_remove)
			*begin_list = (*begin_list)->next;
		if (prev)
			prev->next = next;
		if (next)
			next->prev = prev;
		free(to_remove->content);
		free(to_remove);
	}
}
