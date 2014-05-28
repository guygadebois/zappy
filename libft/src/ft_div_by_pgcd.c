/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_by_pgcd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 15:14:14 by glourdel          #+#    #+#             */
/*   Updated: 2013/11/28 15:27:01 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_div_by_pgcd(int *nbr1, int *nbr2)
{
	int		try;

	try = *nbr1 > *nbr2 ? *nbr1 : *nbr2;
	while (try > 1)
	{
		if (*nbr1 % try == 0 && *nbr2 % try == 0)
		{
			*nbr1 /= try;
			*nbr2 /= try;
			return (1);
		}
		try--;
	}
	return (0);
}
