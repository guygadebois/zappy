/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:46:14 by glourdel          #+#    #+#             */
/*   Updated: 2013/11/25 21:57:39 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*str1;
	unsigned char	*str2;

	if (s1 && s2)
	{
		str1 = (unsigned char *)s1;
		str2 = (unsigned char *)s2;
		i = 0;
		if (n)
		{
			while (i < n)
			{
				if (str1[i] != str2[i])
					return (str1[i] - str2[i]);
				i++;
			}
		}
	}
	return (0);
}
