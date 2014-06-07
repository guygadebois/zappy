/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/28 12:06:56 by glourdel          #+#    #+#             */
/*   Updated: 2014/06/07 19:30:43 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "server.h"

int			main(int argc, char **argv)
{
	int		sock;

	if (argc < 2)
	{
		ft_putendl("Serveur <port>");
		return (0);
	}
	ft_putendl("Serveur here !");
	if ((sock = create_server(ft_atoi(argv[1]))) < 0)
		return (0);
	printf("%d\n", sock);
	ft_putendl("Serveur create !");
	sv_loop(sock);
	return (0);
}
