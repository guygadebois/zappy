/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/19 14:41:14 by glourdel          #+#    #+#             */
/*   Updated: 2013/11/25 21:15:32 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (s1 && s2)
	{
		while (s2[i] != '\0' && i < n)
		{
			s1[i] = s2[i];
			i++;
		}
		while (i < n)
		{
			s1[i] = '\0';
			i++;
		}
		return (s1);
	}
	else
		return (NULL);
}
