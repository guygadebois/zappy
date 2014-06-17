/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_buf.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcouly <dcouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 14:40:43 by dcouly            #+#    #+#             */
/*   Updated: 2014/06/12 16:06:06 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>
#include <cstdlib>
#include "common.h"

char	*read_buf(char *buf)
{
	int		nb_char;
	char	*cmd;
	char	*tmp;

	if ((nb_char = find_ret(buf)))
	{
		cmd = strndup(buf, nb_char);
		tmp = strdup(&((buf)[nb_char + 1]));
		free(buf);
		buf = strdup(tmp);
		free(tmp);
		return (cmd);
	}
	return (NULL);
}
