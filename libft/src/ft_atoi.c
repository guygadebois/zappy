/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:14:24 by glourdel          #+#    #+#             */
/*   Updated: 2014/02/10 17:33:47 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_pwr(int nbr, int power)
{
	int		result;

	result = 1;
	while (power)
	{
		result *= nbr;
		power--;
	}
	return (result);
}

static int	is_white(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v'
		|| c == '\r' || c == '\f')
		return (1);
	else
		return (0);
}

static char	*trim_begin(char *s)
{
	while (*s && is_white(*s))
		s++;
	return (s);
}

int			ft_atoi(char *str)
{
	int		i;
	int		j;
	int		result;
	int		negative;

	i = 0;
	j = 0;
	result = 0;
	negative = 0;
	str = trim_begin(str);
	if (str && (str[0] == '-' || str[0] == '+'))
	{
		negative = (str[0] == '-');
		str = str + 1;
	}
	while (str && str[i] != 0 && str[i] >= 48 && str[i] <= 57)
		i++;
	while (i)
	{
		result += (str[j] - 48) * (ft_pwr(10, i - 1));
		j++;
		i--;
	}
	result = negative ? -result : result;
	return (result);
}
