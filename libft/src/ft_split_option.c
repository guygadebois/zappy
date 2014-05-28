/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_option.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 13:48:46 by glourdel          #+#    #+#             */
/*   Updated: 2014/04/23 16:32:01 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** In insert_option, list.content_size 0 indicates a string
** while 1 indicates a flag
*/
static char		*cpy_option(char *ptr, size_t len)
{
	char	*ret;

	if (!(ret = ft_strnew(len)))
		exit(EXIT_FAILURE);
	ret = ft_strncpy(ret, ptr, len);
	return (ret);
}

static void		insert_option(t_list **list, char **beg_ptr, char **ptr)
{
	t_uint	i;

	i = 1;
	**ptr = '\0';
	ft_lstpushback(list, (void *)*beg_ptr, 0);
	while ((*ptr)[i] && ft_strchr(ALLW_OPT, (int)(*ptr)[i]))
		i++;
	if ((*ptr)[i])
	{
		ft_lstpushback(list, (void *)cpy_option((*ptr) + 1, i), 1);
		*ptr = (*ptr) + i + 1;
		*beg_ptr = *ptr;
	}
	else
	{
		*ptr = NULL;
		*beg_ptr = NULL;
	}
}

t_list			*ft_split_option(char *str, const char c)
{
	t_list	*list;
	char	*ptr;
	char	*beg_ptr;

	list = NULL;
	ptr = str;
	beg_ptr = ptr;
	while ((ptr = ft_strchr(ptr, c)))
		insert_option(&list, &beg_ptr, &ptr);
	if (beg_ptr)
		ft_lstpushback(&list, (void *)beg_ptr, 0);
	return (list);
}
