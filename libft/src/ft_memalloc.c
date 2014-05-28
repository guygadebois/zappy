/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 11:20:04 by glourdel          #+#    #+#             */
/*   Updated: 2013/11/25 21:47:55 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*result;

	result = 0;
	if (size == 0)
		return (NULL);
	else
	{
		result = malloc(size);
		if (!result)
			return (NULL);
		else
		{
			ft_bzero(result, size);
			return (result);
		}
	}
}
