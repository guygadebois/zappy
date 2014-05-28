/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_strtab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 18:06:41 by glourdel          #+#    #+#             */
/*   Updated: 2013/12/28 18:07:46 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_strtab(char **tab)
{
	size_t	count;

	count = 0;
	while (tab && *tab)
	{
		count++;
		tab++;
	}
	return (count);
}
