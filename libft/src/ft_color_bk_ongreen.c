/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_bk_ongreen.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 13:54:57 by glourdel          #+#    #+#             */
/*   Updated: 2013/12/11 14:12:43 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_color_bk_ongreen(char *str)
{
	return (ft_strjoin(ft_strjoin("\033[42;30m", str), "\033[0m"));
}
