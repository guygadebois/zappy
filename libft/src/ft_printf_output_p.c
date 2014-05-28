/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_output_p.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 16:10:15 by glourdel          #+#    #+#             */
/*   Updated: 2014/04/23 16:28:28 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char		*make_output_with_precision(char *output, size_t prec)
{
	size_t	i;
	size_t	offset;
	size_t	output_len;
	char	*ret;

	i = 0;
	offset = 0;
	output_len = ft_strlen(output);
	if (!(ret = (char *)malloc(sizeof(char) * prec + 1)))
		exit(EXIT_FAILURE);
	while (i < prec - output_len)
	{
		*(ret + i + offset) = '0';
		i++;
	}
	ft_strcpy(ret + i + offset, output);
	return (ret);
}

static char		*treat_precision(char *output, t_opt *opt)
{
	char	*ret;

	if (opt->prec < opt->len)
		opt->prec = opt->len;
	ret = make_output_with_precision(output, opt->prec);
	return (ret);
}

static t_uint	check_precision_o(char **output, t_opt *opt)
{
	char	*new_output;

	if (opt->options['.'])
	{
		new_output = treat_precision(*output, opt);
		opt->len = ft_strlen(new_output);
		free(*output);
		*output = new_output;
		return (1);
	}
	return (0);
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

size_t			ft_printf_output_p(va_list *ap, t_opt *opt)
{
	char	*output;

	if (opt->options['l'] == 1)
	{
		if (!(output = ft_itoa_lx((unsigned long)va_arg(*ap, void *))))
			exit(EXIT_FAILURE);
	}
	else
	{
		if (!(output = ft_itoa_lx((unsigned long)va_arg(*ap, void *))))
			exit(EXIT_FAILURE);
	}
	opt->len = ft_strlen(output);
	if (check_precision_o(&output, opt))
	{
		ft_printf_add_sharp_opt_xp(&output, opt);
		print_output_with_prec(output, opt);
	}
	else
	{
		ft_printf_add_sharp_opt_xp(&output, opt);
		ft_print_output_without_prec_p(output, opt);
	}
	free(output);
	return (opt->len > opt->min_len ? opt->len : opt->min_len);
}
