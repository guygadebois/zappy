/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_mult_esc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 14:38:45 by glourdel          #+#    #+#             */
/*   Updated: 2014/01/17 15:02:56 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr_mult_esc(const char *s, const char *allow_chars)
{
	unsigned int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			if (ft_strchr(allow_chars, s[i]))
			{
				if (i == 0 || *(s + i - 1) != 92)
					return ((char *)s + i);
			}
			i++;
		}
	}
	return (NULL);
}
