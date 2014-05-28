/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 12:27:02 by glourdel          #+#    #+#             */
/*   Updated: 2013/11/25 21:09:23 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;

	i = 0;
	if (s1 && s2)
	{
		if (s2[0] == '\0')
			return ((char *)s1);
		while (s1[i])
		{
			if (s1[i] == s2[0])
			{
				j = 0;
				while (s1[i + j] == s2[j] || s2[j] == '\0')
				{
					if (s2[j] == '\0')
						return ((char *)s1 + i);
					j++;
				}
			}
			i++;
		}
	}
	return (NULL);
}
