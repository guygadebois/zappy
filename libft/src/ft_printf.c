/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 15:58:23 by glourdel          #+#    #+#             */
/*   Updated: 2013/12/21 14:42:21 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static t_flag	*init_tab(void)
{
	t_flag	*tab;

	if (!(tab = (t_flag *)malloc(sizeof(t_flag) * 9)))
		exit(EXIT_FAILURE);
	tab[0].flag = "d";
	tab[0].f = &ft_printf_output_id;
	tab[1].flag = "i";
	tab[1].f = &ft_printf_output_id;
	tab[2].flag = "c";
	tab[2].f = &ft_printf_output_c;
	tab[3].flag = "s";
	tab[3].f = &ft_printf_output_s;
	tab[4].flag = "u";
	tab[4].f = &ft_printf_output_u;
	tab[5].flag = "o";
	tab[5].f = &ft_printf_output_o;
	tab[6].flag = "x";
	tab[6].f = &ft_printf_output_x;
	tab[7].flag = "p";
	tab[7].f = &ft_printf_output_p;
	tab[8].flag = NULL;
	return (tab);
}

static size_t	ft_printf_output(va_list *ap, t_flag *opt_tab, char *content)
{
	int		i;
	size_t	ret;

	i = 0;
	while (opt_tab[i].flag)
	{
		if (*ft_last_char(content) == *opt_tab[i].flag)
			return ((*opt_tab[i].f)(ap, ft_printf_get_options(content, ap)));
		i++;
	}
	ret = ft_printf_output_invalid(content, ft_printf_get_options(content, ap));
	return (ret);
}

static void		clean_prog_before_quit(va_list *ap, t_list **list, t_flag *tab)
{
	t_list	*ptr;
	size_t	count;

	count = 0;
	va_end(*ap);
	free(tab);
	while (*list)
	{
		ptr = *list;
		(*list) = (*list)->next;
		if (count % 2 != 0)
			free(ptr->content);
		free(ptr);
		count++;
	}
	*list = NULL;
}

int				ft_printf(const char *format, ...)
{
	va_list	ap;
	t_list	*list;
	size_t	output_len;
	int		count;
	t_flag	*opt_tab;

	count = -1;
	opt_tab = init_tab();
	list = ft_split_option(ft_strdup(format), '%');
	output_len = 0;
	va_start(ap, format);
	while (list)
	{
		if (++count % 2 != 0)
			output_len += ft_printf_output(&ap, opt_tab, (char *)list->content);
		else
		{
			ft_putstr((char *)list->content);
			output_len += ft_strlen((char *)list->content);
		}
		list = list->next;
	}
	clean_prog_before_quit(&ap, &list, opt_tab);
	return (output_len > 2147483647 ? -1 : (int)output_len);
}
