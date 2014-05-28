/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_lu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 17:20:21 by glourdel          #+#    #+#             */
/*   Updated: 2013/12/20 17:55:55 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	find_digits_nbr(long unsigned int nbr)
{
	int		i;

	i = 1;
	while (nbr > 10)
	{
		i++;
		nbr /= 10;
	}
	return (i);
}

static void	fill_digits(char *result, unsigned long int nbr)
{
	char	buf[2];

	if (nbr < 10)
	{
		buf[0] = (char)nbr + 48;
		buf[1] = '\0';
		result = ft_strcat(result, buf);
	}
	else
	{
		fill_digits(result, nbr / 10);
		fill_digits(result, nbr % 10);
	}
}

char		*ft_itoa_lu(long unsigned int n)
{
	int		digits;
	char	*result;

	digits = find_digits_nbr(n);
	result = (char *)malloc(sizeof(char) * (digits + 1));
	if (result)
	{
		ft_bzero(result, sizeof(char) * (digits + 1));
		fill_digits(result, n);
	}
	return (result);
}
