/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 12:13:41 by glourdel          #+#    #+#             */
/*   Updated: 2013/11/25 21:12:58 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			*buffer;

	buffer = NULL;
	i = 0;
	if (s)
	{
		while (s[i])
		{
			if (s[i] == (char)c)
				buffer = (char *)s + i;
			i++;
		}
		if (c == 0)
			return ((char *)s + i);
		else
			return (buffer);
	}
	else
		return (NULL);
}
