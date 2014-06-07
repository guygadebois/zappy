/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_ret.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcouly <dcouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 19:01:32 by dcouly            #+#    #+#             */
/*   Updated: 2014/06/07 19:01:58 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_find_ret(char *str)
{
	char	*target;

	if ((target = ft_strchr(str, '\n')) != NULL)
		return (target - str);
	return (-1);
}
