/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 13:25:35 by glourdel          #+#    #+#             */
/*   Updated: 2013/12/28 21:01:50 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
				ret[i] = (*f)(s[i]);
				i++;
			}
		}
		return (ret);
	}
	else
		return (NULL);
}
