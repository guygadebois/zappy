/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_output_invalid.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 16:18:15 by glourdel          #+#    #+#             */
/*   Updated: 2013/12/19 17:05:21 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_printf_output_invalid(char *content, t_opt *opt)
{
	size_t	i;
	char	empty;

	if (opt->min_len > 1)
	{
		i = 0;
		empty = opt->options['0'] ? '0' : ' ';
		if (opt->options['-'] == 0)
		{
			while (++i < opt->min_len)
				ft_putchar(empty);
			ft_putchar(*ft_last_char(content));
		}
		else
		{
			ft_putchar(*ft_last_char(content));
			while (++i < opt->min_len)
				ft_putchar(' ');
		}
	}
	else
		ft_putchar(*ft_last_char(content));
	return (opt->min_len > 1 ? opt->min_len : 1);
}
