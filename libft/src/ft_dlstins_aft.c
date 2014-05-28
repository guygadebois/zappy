/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstins_aft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 16:31:17 by glourdel          #+#    #+#             */
/*   Updated: 2014/01/28 16:35:54 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_dlstins_aft(t_dlist *ptr, void *data, int size)
{
	t_dlist	*next_ptr;
	t_dlist	*new;

	if (ptr)
	{
		next_ptr = ptr->next;
		new = ft_dlst_create(data, size);
		if (new == NULL)
			return (0);
		ptr->next = new;
		new->prev = ptr;
		new->next = next_ptr;
		if (next_ptr)
			next_ptr->prev = new;
		return (1);
	}
	return (0);
}
