/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:35:55 by glourdel          #+#    #+#             */
/*   Updated: 2013/11/25 21:47:18 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned int	i;

	i = 0;
	if (s1 && s2)
	{
		while (i < n)
		{
			*(unsigned char *)(s1 + i) = *(unsigned char *)(s2 + i);
			if (*(unsigned char *)(s2 + i) == (unsigned char)c)
				return (s1 + i + 1);
			i++;
		}
	}
	return (NULL);
}
