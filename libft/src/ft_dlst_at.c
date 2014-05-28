/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 19:03:20 by glourdel          #+#    #+#             */
/*   Updated: 2014/01/28 19:13:28 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlst_at(t_dlist *begin_list, size_t index)
{
	while (begin_list && index)
	{
		begin_list = begin_list->next;
		index--;
	}
	return (begin_list);
}
