/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_strtab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 12:37:08 by glourdel          #+#    #+#             */
/*   Updated: 2014/05/16 12:45:02 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_print_strtab(char **tab)
{
	int		i;

	i = 0;
	while (tab && tab[i])
	{
		ft_putstr(BLUE);
		ft_putchar('[');
		ft_putnbr(i);
		ft_putstr("] \"");
		ft_putstr(COLOR_END);
		ft_putstr(tab[i]);
		ft_putendl("\"");
		i++;
	}
}
