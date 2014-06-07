// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2014/05/28 11:59:19 by glourdel          #+#    #+#             //
//   Updated: 2014/06/07 21:29:55 by glourdel         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

using namespace std;

void		co_cmd(int sock, char *buf, char *cmd)
{
	sleep(1);
	cout << cmd << endl;
	send(sock, cmd, strlen(cmd) + 1, 0);
	recv(sock, buf, 1024, 0);
}

void		*cl_calcul(char *buf, int sock)
{
	int		c;
	char	*cmd;

	c = rand() % 12;
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

int			cl_new_connection(char **argv)
{
	struct protoent		*proto;
	int					sock;
	struct sockaddr_in	sin;
	int					v;

	proto = getprotobyname("tcp");
	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	cout << sock << endl;
	sin.sin_family = AF_INET;
	sin.sin_port = htons(atoi(argv[2]));
	sin.sin_addr.s_addr = inet_addr(argv[1]);
	if ((v = connect(sock, (const struct sockaddr *)&sin, sizeof(sin))) == -1)
	{
		cout << "CONNECTION ERROR" << endl;
		exit(-1);
	}
	return (sock);
}

int			main(int argc, char **argv)
{
	char				*buf;
	int					sock;

	buf = (char*)malloc(1000);
	if (argc != 3)
		return (0);
	cout << "client here ! " << endl;
	sock = cl_new_connection(argv);
	if (fork())
	{
		sleep(3);
		sock = cl_new_connection(argv);
	}
	do
	{
		cl_calcul(buf, sock);
	} while (strcmp(buf, "end"));
	return (0);
}
