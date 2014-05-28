/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 17:02:28 by glourdel          #+#    #+#             */
/*   Updated: 2013/12/28 19:05:16 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	substract_dir(char **abs_tab, size_t *abs_prof)
{
	free(abs_tab[*abs_prof - 1]);
	abs_tab[*abs_prof - 1] = NULL;
	(*abs_prof)--;
}

static void	add_dir(char **abs_tab, char *dir, size_t *abs_prof)
{
	abs_tab[*abs_prof] = dir;
	abs_tab[*abs_prof + 1] = NULL;
	(*abs_prof)++;
}

static void	increase_tab_len(char ***abs_tab, size_t total_len)
{
	char	**new_tab;
	int		i;

	i = 0;
	if (!(new_tab = (char **)malloc(sizeof(char *) * (total_len + 1))))
		exit(EXIT_FAILURE);
	while ((*abs_tab)[i])
	{
		new_tab[i] = (*abs_tab)[i];
		i++;
	}
	new_tab[i] = NULL;
	free(*abs_tab);
	*abs_tab = new_tab;
}

static char	*concat_final_path(char **abs_tab, char **rel_tab)
{
	size_t	len;
	char	**ptr;
	char	*ret;

	len = 0;
	ptr = abs_tab;
	while (*ptr)
	{
		len += ft_strlen(*ptr) + 1;
		ptr++;
	}
	if (!(ret = ft_strnew(len)))
		exit(EXIT_FAILURE);
	while (*abs_tab)
	{
		ret = ft_strcat(ret, *abs_tab);
		if (*(abs_tab + 1))
			ret = ft_strcat(ret, "/");
		abs_tab++;
	}
	ft_free_strtab(abs_tab);
	ft_free_strtab(rel_tab);
	return (ret);
}

char		*ft_pathadd(const char *abs_path, const char *rel_path)
{
	char	**abs_tab;
	char	**rel_tab;
	size_t	abs_prof;
	size_t	rel_prof;
	size_t	i;

	i = 0;
	(void)rel_path;
	if (!(abs_tab = ft_strsplit_esc(abs_path, '/')))
		return (NULL);
	rel_tab = ft_strsplit_esc(rel_path, '/');
	abs_prof = ft_count_strtab(abs_tab);
	rel_prof = ft_count_strtab(rel_tab);
	increase_tab_len(&abs_tab, abs_prof + rel_prof);
	while (i < rel_prof)
	{
		if (ft_strcmp(rel_tab[i], "..") == 0)
			substract_dir(abs_tab, &abs_prof);
		else if (ft_strcmp(rel_tab[i], ".") != 0)
			add_dir(abs_tab, ft_strdup(rel_tab[i]), &abs_prof);
		i++;
	}
	return (concat_final_path(abs_tab, rel_tab));
}
