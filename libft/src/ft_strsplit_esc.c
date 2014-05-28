/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_esc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 17:43:40 by glourdel          #+#    #+#             */
/*   Updated: 2014/04/16 18:01:32 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

static char	*clean_begin(char const *s, char c)
{
	char	*s_cpy;

	s_cpy = NULL;
	if (s)
	{
		if (!(s_cpy = ft_strdup(s)))
			return (NULL);
		while (*s_cpy && *s_cpy == c)
			s_cpy++;
	}
	return (s_cpy);
}

static char	**initialize_tab(char const *s, char c)
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
			if (*s == c && on_word == 1)
				on_word = 0;
			else if (*s != c && on_word == 0)
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

static char	*get_word_and_append_tab(char **tab, char *buf, char c)
{
	size_t	len;
	size_t	i;
	char	*word;

	len = 0;
	i = 0;
	while (buf[len] && (buf[len] != c || (len && buf[len - 1] == 92)))
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

char		**ft_strsplit_esc(char const *s, char c)
{
	char	*clean_s;
	char	*buf;
	size_t	i;
	char	**tab;

	i = 0;
	clean_s = clean_begin(s, c);
	tab = initialize_tab(clean_s, c);
	if (s && tab && clean_s)
	{
		buf = clean_s;
		while (clean_s[i])
		{
			buf = i == 0 ? clean_s : NULL;
			while (clean_s[i] && clean_s[i] == c
				&& (i == 0 || clean_s[i - 1] != 92))
				buf = clean_s + i++ + 1;
			if (buf && buf[0])
				buf = get_word_and_append_tab(tab, buf, c);
			if (!(clean_s[i] == 0
				|| (clean_s[i] == c && (i == 0 || clean_s[i - 1] != 92))))
				i = i + 1;
		}
	}
	return (tab);
}
