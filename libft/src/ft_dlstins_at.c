/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstins_at.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 19:05:36 by glourdel          #+#    #+#             */
/*   Updated: 2014/02/10 15:24:36 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_dlstins_at(t_dlist **beg_list, size_t index, void *data, int size)
{
	t_dlist	*ptr;

	if (index == 0)
		return (ft_dlstpushfront(beg_list, data, size));
	else
	{
		ptr = ft_dlst_at(*beg_list, index);
		if (ptr == NULL)
			return (ft_dlstpushback(beg_list, data, size));
		return (ft_dlstins_bef(beg_list, ptr, data, size));
	}
}
