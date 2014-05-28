/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_add_sharp_opt.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 10:41:23 by glourdel          #+#    #+#             */
/*   Updated: 2014/04/23 16:28:02 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_printf_add_sharp_opt_o(char **output)
{
	char	*new_output;

	if (!(new_output = ft_strnew(ft_strlen(*output) + 1)))
		exit(EXIT_FAILURE);
	*new_output = '0';
	ft_strcpy(new_output + 1, *output);
	free(*output);
	*output = new_output;
}

void	ft_printf_add_sharp_opt_xp(char **output, t_opt *opt)
{
	char	*new_output;
	size_t	output_len;

	if (opt->options['Z'] && ft_strcmp(*output, "0") == 0)
		**output = '\0';
	output_len = ft_strlen(*output);
	if (!(new_output = ft_strnew(output_len + 2)))
		exit(EXIT_FAILURE);
	*new_output = '0';
	*(new_output + 1) = 'x';
	ft_strcpy(new_output + 2, *output);
	opt->len = output_len + 2;
	free(*output);
	*output = new_output;
}
