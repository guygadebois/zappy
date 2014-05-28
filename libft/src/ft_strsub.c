/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 13:50:47 by glourdel          #+#    #+#             */
/*   Updated: 2013/11/26 12:32:35 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;

	if (s)
	{
		ret = ft_strnew(len);
		if (ret)
			ft_strlcat(ret, (s + start), len + 1);
		return (ret);
	}
	else
		return (0);
}
