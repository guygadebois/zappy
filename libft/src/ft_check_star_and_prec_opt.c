/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_star_and_prec_opt.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 10:57:27 by glourdel          #+#    #+#             */
/*   Updated: 2014/03/07 22:16:36 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		ft_check_star(va_list *ap, t_opt *opt)
{
	int		tmp;

	if (opt->options['*'])
	{
		tmp = va_arg(*ap, int);
		if (tmp < 0)
		{
			tmp *= -1;
			opt->options['-'] = 1;
		}
		opt->min_len = (size_t)tmp;
	}
}

static int	cat_sign(char **output, char *ret, t_opt *opt)
{
	if (**output == '-')
	{
		*ret = '-';
		(*output)++;
		return (1);
	}
	else if (opt->options['+'])
	{
		*ret = '+';
		return (1);
	}
	else if (opt->options[' '])
	{
		*ret = ' ';
		return (1);
	}
	else
		return (0);
}

static char	*make_output_with_precision(char *output, size_t prec, t_opt *opt)
{
	size_t	i;
	size_t	offset;
	size_t	output_len;
	char	*ret;

	i = 0;
	offset = 0;
	if (!(ret = (char *)malloc(sizeof(char) * prec + 2)))
		exit(EXIT_FAILURE);
	if (cat_sign(&output, ret, opt))
		offset++;
	output_len = ft_strlen(output);
	while (i < prec - output_len)
	{
		*(ret + i + offset) = '0';
		i++;
	}
	if (!opt->options['Z'] || ft_strcmp(output, "0") != 0)
		ft_strcpy(ret + i + offset, output);
	return (ret);
}

static char	*treat_precision(char *output, t_opt *opt)
{
	char	*ret;

	if (opt->prec < opt->len)
	{
		opt->prec = opt->len;
		if (*output == '-' || opt->options['+'] || opt->options[' '])
			opt->prec--;
	}
	ret = make_output_with_precision(output, opt->prec, opt);
	return (ret);
}

t_uint		ft_check_precision(char **output, t_opt *opt)
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
