/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:47:43 by glourdel          #+#    #+#             */
/*   Updated: 2013/11/25 21:44:40 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	unsigned int	i;

	i = 0;
	if (s1 && s2)
	{
		ptr1 = (unsigned char *)s1;
		ptr2 = (unsigned char *)s2;
		while (i < n)
		{
			ptr1[i] = ptr2[i];
			i++;
		}
		return (s1);
	}
	else
		return (NULL);
}
