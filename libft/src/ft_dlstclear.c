/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 15:24:39 by glourdel          #+#    #+#             */
/*   Updated: 2014/01/28 15:35:15 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_dlstclear(t_dlist **begin_list)
{
	t_dlist	*buffer;

	if (*begin_list)
	{
		while (*begin_list)
		{
			buffer = *begin_list;
			*begin_list = (*begin_list)->next;
			if (buffer->content)
				free(buffer->content);
			free(buffer);
		}
		*begin_list = NULL;
	}
}
