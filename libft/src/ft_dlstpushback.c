/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstpushback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 15:50:29 by glourdel          #+#    #+#             */
/*   Updated: 2014/01/28 15:59:06 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_dlist	*to_the_end(t_dlist **begin_list)
{
	t_dlist	*result;

	result = *begin_list;
	while (result->next)
		result = result->next;
	return (result);
}

int				ft_dlstpushback(t_dlist **begin_list, void *data, size_t size)
{
	t_dlist	*end_list;

	if ((*begin_list) == 0)
		return ((*begin_list = ft_dlst_create(data, size)) != NULL);
	else
	{
		end_list = to_the_end(begin_list);
		if ((end_list->next = ft_dlst_create(data, size)) == NULL)
			return (0);
		end_list->next->prev = end_list;
		return (1);
	}
}
