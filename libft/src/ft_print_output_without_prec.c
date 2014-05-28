/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_output_without_prec.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 13:22:14 by glourdel          #+#    #+#             */
/*   Updated: 2014/04/23 16:27:44 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		print_sign(char *str, char *options)
{
	if (*str != '-')
	{
		if (options['+'])
			ft_putchar('+');
		else if (options[' '])
			ft_putchar(' ');
	}
	else
		ft_putchar('-');
}

static void		print_nbr_without_sign(char *str)
{
	if (*str == '-')
		str++;
	ft_printf_putstr(str);
}

void			ft_print_output_without_prec(char *output, t_opt *opt)
{
	char	empty;
	size_t	i;

	i = 0;
	if ((opt->options['0']
		&& (*output == '-' || opt->options['+'] || opt->options[' ']))
		|| opt->options['-'])
		print_sign(output, opt->options);
	if (opt->options['-'] == 1)
		print_nbr_without_sign(output);
	empty = opt->options['0'] && !opt->options['-'] ? '0' : ' ';
	while (opt->min_len > i + opt->len)
	{
		ft_putchar(empty);
		i++;
	}
	if (!opt->options['-'] && !opt->options['0'])
		print_sign(output, opt->options);
	if (opt->options['-'] == 0)
		print_nbr_without_sign(output);
}

void			ft_print_output_without_prec_uox(char *output, t_opt *opt)
{
	char	empty;
	size_t	i;

	i = 0;
	if (opt->options['-'] == 1)
		print_nbr_without_sign(output);
	empty = opt->options['0'] && !opt->options['-'] ? '0' : ' ';
	while (opt->min_len > i + opt->len)
	{
		ft_putchar(empty);
		i++;
	}
	if (opt->options['-'] == 0)
		print_nbr_without_sign(output);
}

void			ft_print_output_without_prec_p(char *output, t_opt *opt)
{
	char	empty;
	size_t	i;

	i = -1;
	empty = opt->options['0'] && !opt->options['-'] ? '0' : ' ';
	if (opt->options['-'] == 1)
	{
		print_nbr_without_sign(output);
		while (opt->min_len > ++i + opt->len)
			ft_putchar(empty);
	}
	else
	{
		if (opt->options['0'])
		{
			ft_putchar(*output);
			ft_putchar(*(output + 1));
			output = output + 2;
		}
		while (opt->min_len > ++i + opt->len)
			ft_putchar(empty);
		print_nbr_without_sign(output);
	}
}
