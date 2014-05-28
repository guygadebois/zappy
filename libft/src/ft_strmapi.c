/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 13:25:52 by glourdel          #+#    #+#             */
/*   Updated: 2013/12/28 21:01:12 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*ret;

	i = 0;
	if (s)
	{
		ret = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (ret)
		{
			while (s[i])
			{
				ret[i] = (*f)(i, s[i]);
				i++;
			}
		}
		return (ret);
	}
	else
		return (NULL);
}
