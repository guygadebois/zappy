/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_print_content.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 17:39:06 by glourdel          #+#    #+#             */
/*   Updated: 2013/12/11 15:22:05 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_print_content(t_list *list)
{
	t_list	*buf;

	buf = list;
	while (buf)
	{
		ft_putendl((char *)buf->content);
		buf = buf->next;
	}
}
