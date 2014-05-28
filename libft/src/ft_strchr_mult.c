/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_mult.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 13:22:38 by glourdel          #+#    #+#             */
/*   Updated: 2014/01/17 13:26:08 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr_mult(const char *s, const char *allow_chars)
{
	unsigned int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			if (ft_strchr(allow_chars, s[i]))
				return ((char *)s + i);
			i++;
		}
	}
	return (NULL);
}
