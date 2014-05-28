/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushfront.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 11:46:34 by glourdel          #+#    #+#             */
/*   Updated: 2014/01/20 15:53:38 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstpushfront(t_list **begin_list, void *data, size_t size)
{
	t_list	*new_element;

	if ((*begin_list) == 0)
		return ((*begin_list = ft_create_elem(data, size)) != NULL);
	else
	{
		new_element = ft_create_elem(data, size);
		if (new_element == NULL)
			return (0);
		new_element->next = *begin_list;
		*begin_list = new_element;
		return (1);
	}
}
