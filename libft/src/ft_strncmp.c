/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:25:11 by glourdel          #+#    #+#             */
/*   Updated: 2013/11/25 21:59:32 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned int	longer_s;
	int				s1_length;
	int				s2_length;

	i = 0;
	if (s1 && s2)
	{
		s1_length = ft_strlen(s1);
		s2_length = ft_strlen(s2);
		if (s1_length < s2_length)
			longer_s = s2_length;
		else
			longer_s = s1_length;
		while (i < longer_s && i < n)
		{
			if (s1[i] != s2[i])
				return (s1[i] - s2[i]);
			i++;
		}
	}
	return (0);
}
