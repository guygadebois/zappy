/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_signs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/04 16:33:59 by glourdel          #+#    #+#             */
/*   Updated: 2013/12/04 17:02:12 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_merge_signs(char *str)
{
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	if (str)
	{
		while (str[i] && (str[i] == '-' || str[i] == '+'))
		{
			if (str[i] == '-')
				sign *= -1;
			i++;
		}
		if (i)
		{
			str[i - 1] = (sign > 0) ? '+' : '-';
			str += i - 1;
		}
		return (str);
	}
	return (0);
}
