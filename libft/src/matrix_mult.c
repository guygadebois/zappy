/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_mult.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 14:59:09 by glourdel          #+#    #+#             */
/*   Updated: 2014/02/13 17:12:32 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		line_mult(char **mult, int i, int j, int matrix_size)
{
	int		k;
	int		ret;

	k = 0;
	ret = 0;
	while (k < matrix_size)
	{
		ret += mult[i][k] * mult[k][j];
		k++;
	}
	return (ret);
}

void			matrix_mult(char **dest, char **mult, int matrix_size)
{
	int		i;
	int		j;

	i = 0;
	if (!dest || !mult)
		return ;
	while (i < matrix_size)
	{
		j = 0;
		while (j < matrix_size)
		{
			dest[i][j] = line_mult(mult, i, j, matrix_size);
			j++;
		}
		i++;
	}
}
