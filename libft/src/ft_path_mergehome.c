/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_mergehome.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 17:21:59 by glourdel          #+#    #+#             */
/*   Updated: 2013/12/28 17:32:50 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_path_mergehome(const char *path, const char *home)
{
	char	*ret;

	if (path && home)
	{
		while (*path == *home && *path)
		{
			path++;
			home++;
		}
		if (*home == '\0')
		{
			ret = ft_strnew(ft_strlen(path) + 1);
			*ret = '~';
			ret = ft_strcat(ret, path);
			return (ret);
		}
	}
	return (NULL);
}
