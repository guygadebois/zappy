/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 11:47:18 by glourdel          #+#    #+#             */
/*   Updated: 2013/12/17 16:49:16 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstclear(t_list **begin_list)
{
	t_list	*buffer;

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
