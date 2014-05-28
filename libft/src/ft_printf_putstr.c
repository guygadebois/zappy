/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 11:55:41 by glourdel          #+#    #+#             */
/*   Updated: 2014/04/23 16:28:51 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

/*
** This function prevent from ft_putstr error when str_len is longer
** than INT_MAX (it appens when precision is INT_MAX and a sign is added
** at the beginning of "output" str
*/
void	ft_printf_putstr(char *str)
{
	size_t	len;

	if (str)
	{
		len = ft_strlen(str);
		if (len > 100)
		{
			write(1, str, 100);
			write(1, str + 100, len - 100);
		}
		else
			write(1, str, len);
	}
}
