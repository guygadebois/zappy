/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:54:00 by glourdel          #+#    #+#             */
/*   Updated: 2013/11/25 21:46:07 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;

	i = 0;
	if (s)
	{
		while (i < n)
		{
			if (*((unsigned char *)s + i) == (unsigned char)c)
				return ((void *)s + i);
			i++;
		}
	}
	return (NULL);
}
