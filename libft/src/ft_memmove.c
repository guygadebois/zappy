/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 12:21:31 by glourdel          #+#    #+#             */
/*   Updated: 2013/11/25 21:43:04 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	if (s1 && s2)
	{
		ptr1 = (unsigned char *)s1;
		ptr2 = (unsigned char *)s2;
		if (s2 <= s1)
		{
			while (n)
			{
				ptr1[n - 1] = ptr2[n - 1];
				n--;
			}
		}
		else
			ft_memcpy(s1, s2, n);
		return (s1);
	}
	else
		return (NULL);
}
