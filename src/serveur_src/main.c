/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/28 12:06:56 by glourdel          #+#    #+#             */
/*   Updated: 2014/06/17 17:17:41 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "server.h"
#include "get_arg.h"

int			main(int argc, char **argv)
{
	int		sock;
	t_arg	*arg;

	if ((arg = ft_get_arg(argc, argv)) == NULL)
		return (1);
	if ((sock = create_server(arg->port)) < 0)
		return (0);
	printf("%d\n", sock);
	ft_putendl("Serveur create !");
	sv_loop(sock, arg);
	return (0);
}
