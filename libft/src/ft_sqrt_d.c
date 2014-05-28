/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 13:04:40 by glourdel          #+#    #+#             */
/*   Updated: 2014/01/08 10:42:53 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	find_closest_int_sqrt(double nbr)
{
	int		ret;
	double	square;

	ret = 1;
	while ((square = (double)(ret * ret)) < nbr)
		ret++;
	if (square - nbr < (double)((ret - 1) * (ret - 1)))
		return ((ret > 0 ? ret : 1));
	else
		return ((ret - 1 > 0 ? ret - 1 : 1));
}

double		ft_sqrt_d(double nbr)
{
	double	ret;
	int		i;

	if (nbr <= 0)
		return (0);
	else if (nbr == 1)
		return (1);
	ret = (double)find_closest_int_sqrt(nbr);
	i = 0;
	while (i < 6)
	{
		ret = (ret + nbr / ret) / 2;
		i++;
	}
	return (ret);
}
