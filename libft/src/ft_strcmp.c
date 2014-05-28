/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/19 17:12:51 by glourdel          #+#    #+#             */
/*   Updated: 2013/11/25 21:59:10 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int		i;
	int		s1_length;
	int		s2_length;
	int		longer_s;

	i = 0;
	if (s1 && s2)
	{
		s1_length = ft_strlen(s1);
		s2_length = ft_strlen(s2);
		if (s1_length < s2_length)
			longer_s = s2_length;
		else
			longer_s = s1_length;
		while (i < longer_s)
		{
			if (s1[i] != s2[i])
				return (s1[i] - s2[i]);
			i++;
		}
	}
	return (0);
}
