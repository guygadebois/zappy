/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 12:12:23 by glourdel          #+#    #+#             */
/*   Updated: 2013/12/13 12:19:32 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_char_count(const char *str, const char c)
{
	int		i;
	size_t	ret;

	i = 0;
	ret = 0;
	if (str)
	{
		while (str[i])
		{
			if (str[i] == c)
				ret++;
			i++;
		}
	}
	return (ret);
}
