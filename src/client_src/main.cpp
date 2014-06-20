// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2014/05/28 11:59:19 by glourdel          #+#    #+#             //
/*   Updated: 2014/06/20 19:23:58 by dcouly           ###   ########.fr       */
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <cstring>
#include "common.h"

using namespace std;

void		co_cmd(int sock, char *buf, char *cmd)
{
	int	i;

	cout << cmd << endl;
	send(sock, cmd, strlen(cmd) + 1, 0);
	bzero(buf, 1024);
	i = recv(sock, buf, 1023, 0);
	buf[i] = 0;
	printf("BUF : %s\n", buf);
}

void		*cl_calcul(char *buf, int sock)
{
	int		c;
	char	*cmd;

	c = rand() % 4;
	switch (c)
	{
	case (0) :
		cmd = strdup("avance\n");
		break ;
	case (1) :
		cmd = strdup("droite\n");
		break ;
	case (2) :
		cmd = strdup("gauche\n");
		break ;
	case (3) :
		cmd = strdup("voir\n");
		break ;
	case (4) :
		cmd = strdup("inventaire\n");
		break ;
	case (5) :
		cmd = strdup("prend truc\n");
		break ;
	case (6) :
		cmd = strdup("poser truc\n");
		break ;
	case (7) :
		cmd = strdup("expulse\n");
		break ;
	case (8) :
		cmd = strdup("broadcaster\n");
		break ;
	case (9) :
		cmd = strdup("incantation\n");
		break ;
	case (10) :
		cmd = strdup("fork\n");
		break ;
	case (11) :
		cmd = strdup("connect_nbr\n");
		break ;
	}
	co_cmd(sock, buf, cmd);
	free(cmd);
	return (buf);
}

int			main(int argc, char **argv)
{
	char				*buf;
	int					sock;
	char				*team;

	buf = (char*)malloc(1000);
	if (argc != 4)
		return (0);
	cout << "client here ! " << endl;
	team = strcat(argv[3], "\n");
	sock = cl_new_connection(argv[1], argv[2], team);
/*	if (fork())
	{
		sleep(3);
		sock = cl_new_connection(argv[1], argv[2], team);
	}
*/	do
	{
		cl_calcul(buf, sock);
	} while (strcmp(buf, "end"));
	return (0);
}
