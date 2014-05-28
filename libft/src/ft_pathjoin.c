/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 11:07:40 by glourdel          #+#    #+#             */
/*   Updated: 2014/03/26 14:34:55 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_pathjoin(char *dir_path, char *name)
{
	char	*tmp;
	char	*ret;

	if (!(tmp = ft_strjoin(dir_path, "/")))
		return (NULL);
	if (!(ret = ft_strjoin(tmp, name)))
		return (NULL);
	free(tmp);
	return (ret);
}
