/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strshift.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 14:27:00 by glourdel          #+#    #+#             */
/*   Updated: 2014/01/21 14:29:49 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_strshift(char *dest, char *src)
{
	if (dest && src && dest < src)
	{
		while (*dest && *src)
		{
			*dest = *src;
			dest++;
			src++;
		}
		while (dest < src && *dest)
		{
			*dest = '\0';
			dest++;
		}
	}
}
