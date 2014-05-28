/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_esc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/20 16:02:03 by glourdel          #+#    #+#             */
/*   Updated: 2014/01/20 16:02:45 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr_esc(const char *s, const char c)
{
	unsigned int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			if (s[i] == c)
			{
				if (i == 0 || *(s + i - 1) != 92)
					return ((char *)s + i);
			}
			i++;
		}
	}
	return (NULL);
}
