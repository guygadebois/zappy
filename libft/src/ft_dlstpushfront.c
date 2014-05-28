/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstpushfront.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 15:44:00 by glourdel          #+#    #+#             */
/*   Updated: 2014/01/28 16:00:09 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_dlstpushfront(t_dlist **begin_list, void *data, size_t size)
{
	t_dlist	*new_element;

	if ((*begin_list) == 0)
		return ((*begin_list = ft_dlst_create(data, size)) != NULL);
	else
	{
		new_element = ft_dlst_create(data, size);
		if (new_element == NULL)
			return (0);
		new_element->next = *begin_list;
		(*begin_list)->prev = new_element;
		*begin_list = new_element;
		return (1);
	}
}
