/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_remove_elem.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 11:46:43 by glourdel          #+#    #+#             */
/*   Updated: 2014/06/22 20:40:27 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lst_remove_elem(t_list **list, size_t index)
{
	t_list	*buf_tail;
	t_list	*ptr;

	buf_tail = NULL;
	if (index == 0)
	{
		ptr = (*list)->next;
	 	*list = ptr;
		return ;
	}
	if (list && *list)
	{
		ptr = *list;
		while (ptr && index)
		{
			index--;
			buf_tail = ptr;
			ptr = ptr->next;
		}
		if (buf_tail)
			buf_tail->next = ptr->next;
		else
			*list = ptr->next;
		if (ptr->content)
			free(ptr->content);
		free(ptr);
	}
}
