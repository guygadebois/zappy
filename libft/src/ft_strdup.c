/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/21 15:07:50 by glourdel          #+#    #+#             */
/*   Updated: 2013/11/25 21:33:02 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char			*ptr;
	size_t			s1_len;
	unsigned int	i;

	if (s1)
	{
		s1_len = ft_strlen(s1);
		ptr = (char *)malloc(sizeof(char) * s1_len + 1);
		i = 0;
		if (ptr)
		{
			while (i < s1_len)
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
