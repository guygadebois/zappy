/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 15:09:15 by glourdel          #+#    #+#             */
/*   Updated: 2013/12/19 15:44:32 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	find_digits_nbr(t_uint nbr)
{
	int		i;

	i = 1;
	while (nbr > 8)
	{
		i++;
		nbr /= 8;
	}
	return (i);
}

static void	fill_digits(char *result, long unsigned int nbr)
{
	char	buf[2];

	if (nbr < 8)
	{
		buf[0] = (char)nbr + 48;
		buf[1] = '\0';
		result = ft_strcat(result, buf);
	}
	else
	{
		fill_digits(result, nbr / 8);
		fill_digits(result, nbr % 8);
	}
}

char		*ft_itoa_o(t_uint n)
{
	int		digits;
	char	*result;

	digits = find_digits_nbr(n);
	result = (char *)malloc(sizeof(char) * (digits + 1));
	if (result)
	{
		ft_bzero(result, sizeof(char) * (digits + 1));
		fill_digits(result, (long unsigned int)n);
	}
	return (result);
}
