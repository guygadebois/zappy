/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 11:48:28 by glourdel          #+#    #+#             */
/*   Updated: 2014/01/20 15:54:12 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*to_the_end(t_list **begin_list)
{
	t_list	*result;

	result = *begin_list;
	while (result->next)
		result = result->next;
	return (result);
}

int				ft_lstpushback(t_list **begin_list, void *data, size_t size)
{
	t_list	*end_list;

	if ((*begin_list) == 0)
		return ((*begin_list = ft_create_elem(data, size)) != NULL);
	else
	{
		end_list = to_the_end(begin_list);
		return ((end_list->next = ft_create_elem(data, size)) != NULL);
	}
}
