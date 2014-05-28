/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 14:29:16 by glourdel          #+#    #+#             */
/*   Updated: 2013/11/26 15:19:35 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_white(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	else
		return (0);
}

char		*ft_strtrim(char const *s)
{
	char	*ret;
	size_t	s_len;

	if (s)
	{
		while (*s && is_white(*s))
			s++;
		s_len = ft_strlen(s);
		while (s_len && is_white(s[s_len - 1]))
			s_len--;
		ret = ft_strnew(s_len);
		if (ret)
			ft_strncpy(ret, s, s_len);
		return (ret);
	}
	else
		return (NULL);
}
