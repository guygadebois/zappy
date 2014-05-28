/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 13:25:55 by glourdel          #+#    #+#             */
/*   Updated: 2013/11/25 21:42:29 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	if (b)
	{
		while (len)
		{
			*((unsigned char *)b + len - 1) = (unsigned char)c;
			len--;
		}
		return (b);
	}
	else
		return (NULL);
}
