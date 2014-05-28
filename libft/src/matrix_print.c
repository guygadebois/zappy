/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 17:16:11 by glourdel          #+#    #+#             */
/*   Updated: 2014/02/13 17:41:17 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_line(char *line, int line_width)
{
	int		i;

	i = 0;
	while (line && i < line_width)
	{
		ft_putnbr(line[i]);
		ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}

void		matrix_print(char **matrix, int matrix_size)
{
	int		i;

	i = 0;
	if (!matrix)
		return ;
	while (i < matrix_size)
	{
		print_line(matrix[i], matrix_size);
		i++;
	}
	ft_putchar('\n');
}
