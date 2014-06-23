/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sendall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/22 16:22:54 by glourdel          #+#    #+#             */
/*   Updated: 2014/06/23 17:55:41 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include <stdio.h>
#include "libft.h"

int		ft_sendall(int s, char *buf, int len)
{
	int		total;
	int		bytesleft;
	int		n;

	total = 0;
	bytesleft = len;
	while (total < len)
	{
		n = send(s, buf + total, bytesleft, 0);
		if (n == -1)
		{
			printf("%sERROR: Could only send %s%d%s bytes", RED, YELLOW, \
				total, RED);
			printf("on socket %s%d%s because send() failed !%s\n", YELLOW, \
				s, RED, COLOR_END);
			return (0);
		}
		total += n;
		bytesleft -= n;
	}
	return (1);
}
