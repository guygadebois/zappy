/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 16:47:29 by glourdel          #+#    #+#             */
/*   Updated: 2013/11/26 17:36:48 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;
	t_list	*buf;

	if (lst)
	{
		ret = ft_lstnew(lst->content, lst->content_size);
		ret = (*f)(ret);
		buf = ret;
		lst = lst->next;
		while (lst)
		{
			buf->next = ft_lstnew(lst->content, lst->content_size);
			buf->next = (*f)(buf->next);
			lst = lst->next;
			buf = buf->next;
		}
		return (ret);
	}
	else
		return (NULL);
}
