/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_output_id.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 15:47:14 by glourdel          #+#    #+#             */
/*   Updated: 2013/12/21 10:12:33 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	get_len(char *str, char *options)
{
	size_t	len;

	len = ft_strlen(str);
	if ((options[' '] || options['+']) && *str != '-')
		return (len + 1);
	else
		return (len);
}

static void		print_output_with_prec(char *output, t_opt *opt)
{
	size_t	i;

	i = 0;
	if (opt->options['Z'] == 0 || ft_strcmp(output, "0") != 0)
	{
		if (opt->options['-'])
			ft_printf_putstr(output);
		while (opt->min_len > i + opt->len)
		{
			ft_putchar(' ');
			i++;
		}
		if (!opt->options['-'])
			ft_printf_putstr(output);
	}
	else
	{
		while (opt->min_len > i + opt->len - 1)
		{
			ft_putchar(' ');
			i++;
		}
		opt->len = 0;
	}
}

size_t			ft_printf_output_id(va_list *ap, t_opt *opt)
{
	char	*output;

	if (opt->options['l'] == 1)
	{
		if (!(output = ft_itoa_l(va_arg(*ap, long int))))
			exit(EXIT_FAILURE);
	}
	else
	{
		if (!(output = ft_itoa(va_arg(*ap, int))))
			exit(EXIT_FAILURE);
	}
	opt->len = get_len(output, opt->options);
	if (ft_check_precision(&output, opt))
		print_output_with_prec(output, opt);
	else
		ft_print_output_without_prec(output, opt);
	free(output);
	return (opt->len > opt->min_len ? opt->len : opt->min_len);
}
