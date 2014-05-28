/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_output_s.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 15:42:40 by glourdel          #+#    #+#             */
/*   Updated: 2013/12/20 16:46:21 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"

static char	*sub_output(char *output, size_t prec)
{
	char	*new_output;
	size_t	i;

	i = 0;
	if (prec < ft_strlen(output))
	{
		new_output = ft_strnew(prec);
		while (i < prec)
		{
			new_output[i] = output[i];
			i++;
		}
		free(output);
		return (new_output);
	}
	return (output);
}

static void	print_with_min_len(char *output, t_opt *opt)
{
	size_t	i;
	char	empty;

	i = 0;
	empty = opt->options['0'] ? '0' : ' ';
	if (opt->options['-'] == 0)
	{
		while (i < opt->min_len - opt->len)
		{
			ft_putchar(empty);
			i++;
		}
		ft_putstr(output);
	}
	else
	{
		ft_putstr(output);
		while (i < opt->min_len - opt->len)
		{
			ft_putchar(' ');
			i++;
		}
	}
}

size_t		ft_printf_output_s(va_list *ap, t_opt *opt)
{
	char	*output;

	output = va_arg(*ap, char *);
	if (!output)
		output = ft_strdup("(null)");
	else
		output = ft_strdup(output);
	if (opt->options['.'] && !opt->options['S'])
		output = sub_output(output, opt->prec);
	opt->len = ft_strlen(output);
	if (opt->min_len > opt->len)
		print_with_min_len(output, opt);
	else
		ft_putstr(output);
	free(output);
	return (opt->len >= opt->min_len ? opt->len : opt->min_len);
}
