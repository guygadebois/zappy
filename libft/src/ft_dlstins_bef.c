/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstins_bef.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 16:31:32 by glourdel          #+#    #+#             */
/*   Updated: 2014/01/28 16:40:04 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_dlstins_bef(t_dlist **beg_list, t_dlist *ptr, void *data, int size)
{
	t_dlist	*prev_ptr;
	t_dlist	*new;

	if (beg_list && *beg_list && ptr)
	{
		if (*beg_list == ptr)
			return (ft_dlstpushfront(beg_list, data, size));
		prev_ptr = ptr->prev;
		new = ft_dlst_create(data, size);
		if (new == NULL)
			return (0);
		prev_ptr->next = new;
		new->prev = prev_ptr;
		new->next = ptr;
		ptr->prev = new;
		return (1);
	}
	return (0);
}
