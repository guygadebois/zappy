/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_mult.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/04 18:23:55 by glourdel          #+#    #+#             */
/*   Updated: 2014/04/16 17:59:47 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

static int	is_allowed(char c, char *allowed)
{
	int		i;

	i = 0;
	while (allowed[i])
	{
		if (c == allowed[i])
			return (1);
		i++;
	}
	return (0);
}

static char	**initialize_tab(char const *s, char *allow)
{
	char	**tab;
	size_t	count;
	int		on_word;

	count = 0;
	if (s)
	{
		on_word = *s ? 1 : 0;
		while (*s)
		{
			if (!is_allowed(*s, allow) && on_word == 1)
				on_word = 0;
			else if (is_allowed(*s, allow) && on_word == 0)
			{
				count++;
				on_word = 1;
			}
			s++;
		}
		tab = (char **)malloc(sizeof(char *) * (count + 2));
		tab[0] = NULL;
		return (tab);
	}
	return (NULL);
}

static void	append_tab(char **tab, char *word)
{
	size_t	i;

	i = 0;
	while (tab[i])
		i++;
	tab[i] = word;
	tab[i + 1] = NULL;
}

static char	*get_word_and_append_tab(char **tab, char *buf, char *allow)
{
	size_t	len;
	size_t	i;
	char	*word;

	len = 0;
	i = 0;
	while (buf[len] && is_allowed(buf[len], allow))
		len++;
	word = ft_strnew(len);
	if (word)
	{
		while (i < len)
		{
			word[i] = buf[i];
			i++;
		}
		word[i] = '\0';
		append_tab(tab, word);
	}
	return (NULL);
}

char		**ft_strsplit_mult(char const *s, char *allow)
{
	char	*clean_s;
	char	*buf;
	size_t	i;
	char	**tab;

	i = 0;
	clean_s = ft_clean_begin((char *)s, allow);
	tab = initialize_tab(clean_s, allow);
	if (s && tab && clean_s)
	{
		buf = clean_s;
		while (clean_s[i])
		{
			buf = i == 0 ? clean_s : NULL;
			while (clean_s[i] && !is_allowed(clean_s[i], allow))
			{
				buf = clean_s + i + 1;
				i++;
			}
			if (buf && buf[0])
				buf = get_word_and_append_tab(tab, buf, allow);
			i = (clean_s[i] == 0 || !is_allowed(clean_s[i], allow)) ? i : i + 1;
		}
	}
	return (tab);
}
