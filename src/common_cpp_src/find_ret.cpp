/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_ret.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcouly <dcouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 14:47:24 by dcouly            #+#    #+#             */
/*   Updated: 2014/06/11 14:49:42 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>

int		find_ret(char *str)
{
	char	*target;

	if ((target = strchr(str, '\n')) != NULL)
		return (target - str);
	return (-1);
}
