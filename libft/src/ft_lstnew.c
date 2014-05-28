/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 13:51:09 by glourdel          #+#    #+#             */
/*   Updated: 2013/11/26 15:30:25 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_elem;

	content_size = content ? content_size : 0;
	new_elem = ft_memalloc(sizeof(t_list));
	if (new_elem)
	{
		new_elem->content = ft_memalloc(content_size);
		if (new_elem->content)
		{
			ft_memcpy(new_elem->content, content, content_size);
			new_elem->content_size = content_size;
			new_elem->next = NULL;
		}
		else
			return (NULL);
	}
	return (new_elem);
}
