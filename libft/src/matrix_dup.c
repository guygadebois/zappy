/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_dup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 18:04:39 by glourdel          #+#    #+#             */
/*   Updated: 2014/02/13 18:20:51 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		**matrix_new(int matrix_size)
{
	char	**ret;
	int		i;

	i = 0;
	ret = (char **)malloc(sizeof(char *) * matrix_size);
	if (ret == NULL)
		return (NULL);
	while (i < matrix_size)
	{
		if (!(ret[i] = ft_strnew(matrix_size - 1)))
			return (NULL);
		i++;
	}
	return (ret);
}

char		**matrix_dup(char **src, int matrix_size)
{
	char	**dest;
	int		i;
	int		j;

	if (src == NULL)
		return (NULL);
	dest = matrix_new(matrix_size);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < matrix_size)
	{
		j = 0;
		while (j < matrix_size)
		{
			dest[i][j] = src[i][j];
			j++;
		}
		i++;
	}
	return (dest);
}
