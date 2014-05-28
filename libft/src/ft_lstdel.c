/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 14:58:06 by glourdel          #+#    #+#             */
/*   Updated: 2013/11/25 15:05:45 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*buf_head;
	t_list	*buf_tail;

	if (alst && *alst)
	{
		buf_head = *alst;
		while (buf_head)
		{
			buf_tail = buf_head;
			buf_head = buf_head->next;
			ft_lstdelone(&buf_tail, del);
		}
		*alst = NULL;
	}
}
