/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_x_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 16:00:09 by glourdel          #+#    #+#             */
/*   Updated: 2013/12/19 16:00:35 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_init_x_tab(void)
{
	char	*tab;

	if (!(tab = (char *)malloc(sizeof(tab) * 16)))
		exit(EXIT_FAILURE);
	tab[0] = '0';
	tab[1] = '1';
	tab[2] = '2';
	tab[3] = '3';
	tab[4] = '4';
	tab[5] = '5';
	tab[6] = '6';
	tab[7] = '7';
	tab[8] = '8';
	tab[9] = '9';
	tab[10] = 'a';
	tab[11] = 'b';
	tab[12] = 'c';
	tab[13] = 'd';
	tab[14] = 'e';
	tab[15] = 'f';
	return (tab);
}
