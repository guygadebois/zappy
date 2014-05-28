/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 11:54:58 by glourdel          #+#    #+#             */
/*   Updated: 2013/11/25 21:14:15 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char			*result;
	unsigned int	i;

	result = 0;
	i = 0;
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	else
	{
		while (i < size + 1)
		{
			result[i] = '\0';
			i++;
		}
		return (result);
	}
}
