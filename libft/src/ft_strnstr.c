/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:04:02 by glourdel          #+#    #+#             */
/*   Updated: 2013/11/27 12:30:31 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (s1 && s2)
	{
		if (s2[0] == '\0')
			return ((char *)s1);
		while (s1[i] && i < n)
		{
			if (s1[i] == s2[0])
			{
				j = 0;
				while ((i + j) < n && s2[j] && s1[i + j] == s2[j])
					j++;
				if (s2[j] == '\0')
					return ((char *)s1 + i);
			}
			i++;
		}
	}
	return (NULL);
}
