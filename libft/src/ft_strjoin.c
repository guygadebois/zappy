/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 14:19:17 by glourdel          #+#    #+#             */
/*   Updated: 2013/11/25 21:30:32 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;

	if (s1 && s2)
	{
		ret = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
		if (ret)
		{
			ret = ft_strcat(ret, s1);
			ret = ft_strcat(ret, s2);
		}
		return (ret);
	}
	else
		return (NULL);
}
