/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/27 10:48:53 by glourdel          #+#    #+#             */
/*   Updated: 2013/12/17 16:51:08 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_create_elem(void *content, size_t size)
{
	t_list	*my_list;

	my_list = (t_list *)malloc(sizeof(*my_list));
	if (my_list)
	{
		my_list->next = NULL;
		my_list->content = content;
		my_list->content_size = size;
	}
	return (my_list);
}
