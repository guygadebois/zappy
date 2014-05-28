/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_get_options.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 15:56:25 by glourdel          #+#    #+#             */
/*   Updated: 2014/03/07 22:24:59 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	get_next_nbr(char **content_ptr)
{
	size_t	ret;

	ret = 0;
	while (**content_ptr >= '0' && **content_ptr <= '9')
	{
		ret *= 10;
		ret += **content_ptr - 48;
		(*content_ptr)++;
	}
	return (ret);
}

static size_t	get_width(char **content_ptr, t_opt *ret, va_list *ap)
{
	int		tmp;
	size_t	width;

	if (**content_ptr == '*')
	{
		tmp = va_arg(*ap, int);
		if (tmp < 0)
		{
			tmp *= -1;
			ret->options['-'] = 1;
		}
		width = (size_t)tmp;
		(*content_ptr)++;
	}
	else
		width = get_next_nbr(content_ptr);
	width = width <= 2147483647 ? width : 0;
	return (width);
}

static size_t	get_precision(char **content_ptr, t_opt *ret, va_list *ap)
{
	int		tmp;
	size_t	precision;

	ret->options['.'] = 1;
	(*content_ptr)++;
	if (**content_ptr == '*')
	{
		tmp = va_arg(*ap, int);
		if (tmp < 0)
		{
			precision = 0;
			ret->options['S'] = 1;
		}
		precision = (size_t)tmp;
		(*content_ptr)++;
	}
	else
		precision = get_next_nbr(content_ptr);
	precision = precision <= 2147483647 ? precision : 1;
	if (precision == 0)
		ret->options['Z'] = 1;
	return (precision);
}

t_opt			*ft_printf_get_options(char *content, va_list *ap)
{
	t_opt	*ret;
	t_uint	index;

	if (!(ret = (t_opt *)malloc(sizeof(t_opt))))
		exit(EXIT_FAILURE);
	ret->min_len = 0;
	ret->prec = 0;
	if (!(ret->options = ft_strnew(127)))
		exit(EXIT_FAILURE);
	while (content && *content)
	{
		if (*content == '*' || (*content >= '1' && *content <= '9'))
			ret->min_len = get_width(&content, ret, ap);
		if (*content == '.')
			ret->prec = get_precision(&content, ret, ap);
		if (!(*content >= '1' && *content <= '9')
			&& *content != '.' && *content != '*')
		{
			index = (t_uint)(unsigned char)*content;
			ret->options[index] = 1;
			content++;
		}
	}
	return (ret);
}
