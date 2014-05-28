/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_remove_at.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 19:00:15 by glourdel          #+#    #+#             */
/*   Updated: 2014/01/28 19:14:43 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_dlst_remove_at(t_dlist **begin_list, size_t index)
{
	ft_dlst_remove(begin_list, ft_dlst_at(*begin_list, index));
}
