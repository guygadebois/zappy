/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 19:06:33 by glourdel          #+#    #+#             */
/*   Updated: 2013/12/28 21:00:20 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strndup(const char *s1, const size_t n)
{
	char			*ptr;
	size_t			s1_len;
	size_t			len;
	unsigned int	i;

	if (s1)
	{
		s1_len = ft_strlen(s1);
		len = s1_len < n ? s1_len : n;
		ptr = (char *)malloc(sizeof(char) * len + 1);
		i = 0;
		if (ptr)
		{
			while (i < len)
			{
				ptr[i] = s1[i];
				i++;
			}
			ptr[i] = '\0';
			return (ptr);
		}
	}
	return (NULL);
}
