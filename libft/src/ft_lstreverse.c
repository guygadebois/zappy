/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 11:48:55 by glourdel          #+#    #+#             */
/*   Updated: 2013/11/28 11:49:09 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstreverse(t_list **begin_list)
{
	t_list	*front_buf;
	t_list	*tail_buf;

	front_buf = *begin_list;
	tail_buf = *begin_list;
	while (front_buf)
	{
		front_buf = front_buf->next;
		if (tail_buf == *begin_list)
			(*begin_list)->next = 0;
		else
			(*begin_list)->next = tail_buf;
		tail_buf = *begin_list;
		if (front_buf)
			*begin_list = front_buf;
	}
}
