/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_output_c.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 15:40:33 by glourdel          #+#    #+#             */
/*   Updated: 2013/12/19 14:28:17 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

size_t	ft_printf_output_c(va_list *ap, t_opt *opt)
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
			ft_putchar(va_arg(*ap, int));
		}
		else
		{
			ft_putchar(va_arg(*ap, int));
			while (++i < opt->min_len)
				ft_putchar(' ');
		}
	}
	else
		ft_putchar(va_arg(*ap, int));
	return (opt->min_len > 1 ? opt->min_len : 1);
}
