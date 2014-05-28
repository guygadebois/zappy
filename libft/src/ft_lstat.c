/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 11:47:47 by glourdel          #+#    #+#             */
/*   Updated: 2013/11/28 11:47:56 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstat(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;

	i = 1;
	if (nbr < 1)
		return (0);
	while (i < nbr && begin_list)
	{
		begin_list = begin_list->next;
		i++;
	}
	return (begin_list);
}
