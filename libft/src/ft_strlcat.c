/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 11:49:24 by glourdel          #+#    #+#             */
/*   Updated: 2013/11/26 12:33:16 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	size_t			result;
	unsigned int	dst_len;
	unsigned int	src_len;

	if (!(dst && src))
		return (0);
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	result = size < dst_len ? size + src_len : dst_len + src_len;
	i = 0;
	j = 0;
	if (size > dst_len)
	{
		while (dst[i] != '\0')
			i++;
		while (src[j] != '\0' && j < (size - dst_len - 1))
		{
			dst[i + j] = src[j];
			j++;
		}
		dst[i + j] = '\0';
	}
	return ((size == 0) ? src_len : result);
}
