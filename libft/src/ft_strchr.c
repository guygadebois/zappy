/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 12:06:23 by glourdel          #+#    #+#             */
/*   Updated: 2013/11/25 21:37:20 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			if (s[i] == (char)c)
				return ((char *)s + i);
			i++;
		}
		if (c == 0)
			return ((char *)s + i);
	}
	return (NULL);
}
