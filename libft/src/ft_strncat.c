/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 11:33:13 by glourdel          #+#    #+#             */
/*   Updated: 2013/11/25 21:18:29 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *s1, const char *s2, size_t nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (s1 && s2)
	{
		while (s1[i] != '\0')
			i++;
		while (s2[j] != '\0' && j < nb)
		{
			s1[i + j] = s2[j];
			j++;
		}
		s1[i + j] = '\0';
		return (s1);
	}
	else
		return (NULL);
}
