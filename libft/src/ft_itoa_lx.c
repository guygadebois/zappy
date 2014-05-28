/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_lx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 16:17:37 by glourdel          #+#    #+#             */
/*   Updated: 2013/12/21 14:17:22 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		find_digits_nbr(unsigned long nbr)
{
	int		i;

	i = 1;
	while (nbr > 16)
	{
		i++;
		nbr /= 16;
	}
	return (i);
}

static void		fill_digits(char *x_tab, char *result, long unsigned int nbr)
{
	char	buf[2];

	if (nbr < 16)
	{
		buf[0] = x_tab[nbr];
		buf[1] = '\0';
		result = ft_strcat(result, buf);
	}
	else
	{
		fill_digits(x_tab, result, nbr / 16);
		fill_digits(x_tab, result, nbr % 16);
	}
}

char			*ft_itoa_lx(unsigned long n)
{
	int		digits;
	char	*result;
	char	*x_tab;

	x_tab = ft_init_x_tab();
	digits = find_digits_nbr(n);
	result = (char *)malloc(sizeof(char) * (digits + 1));
	if (result)
	{
		ft_bzero(result, sizeof(char) * (digits + 1));
		fill_digits(x_tab, result, n);
	}
	return (result);
}
