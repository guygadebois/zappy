// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2014/05/28 11:59:19 by glourdel          #+#    #+#             //
/*   Updated: 2014/06/26 19:50:55 by sbodovsk         ###   ########.fr       */
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
#include "client.h"

using namespace std;

void		co_cmd(int sock, char *buf, char *cmd)
{
	int	i;

	cout << cmd << endl;
	if (send(sock, cmd, strlen(cmd) + 1, 0) == -1)
		exit(1);
	bzero(buf, 1024);
	i = recv(sock, buf, 1023, 0);
	if (i == -1)
		exit(-1);
	buf[i] = 0;
	printf("BUF : %s\n", buf);
}

typedef	struct		s_ia
{
			int		eggs;
}					t_ia;



void		*cl_calcul(char *buf, int sock, char const *tab[], int i)
{
//	int		c;
	char	*cmd;

	sleep(1);
	printf("\nprintf : %s\n", tab[i]);
	cmd = strdup(tab[i]);
	printf("cmd = %s", cmd);

	/*c = rand() % 2;
	c = 9;
	switch (c)
	{
	case (0) :
		cmd = strdup(""avance"\n");
		break ;
	case (1) :
		cmd = strdup("voir\n");
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
		cmd = strdup(""prend linemate"\n");
		break ;
	case (6) :
		cmd = strdup(""pose linemate"\n");
		break ;
	case (7) :
		cmd = strdup("expulse\n");
		break ;
	case (8) :
		cmd = strdup("broadcaster TOTO\n");
		break ;
	case (9) :
		cmd = strdup(""incantation"\n");
		break ;
	case (10) :
		cmd = strdup("fork\n");
		break ;
	case (11) :
		cmd = strdup("connect_nbr\n");
		break ;
	}
	*/
	co_cmd(sock, buf, cmd);
	free(cmd);
	return (buf);

	}

int			main(int argc, char **argv)
{
	char				*buf;
	int					sock;
	char				*team;
	char				*addr;
	char				*port;
	int					nb;
	char const			*tab_cmd[] = {"avance\n", "prend linemate\n", "droite\n", "droite\n", "avance\n", "pose linemate\n", "droite\n", "droite\n", "avance\n", "broadcast hello\n", "prend deraumere\n", "prend nourriture\n", "droite\n"
									 , "droite\n", "avance\n", "pose deraumere\n", "droite\n", "droite\n", "avance\n", "prend sibur\n", "droite\n", "droite\n", "avance\n", 
									 "pose sibur\n", "broadcast hello\n", "droite\n", "droite\n", "avance\n", "prend mendiane\n", "prend nourriture\n", "droite\n", 
									 "droite\n", "avance\n", "pose mendiane\n", "droite\n", "droite\n", "avance\n", "prend phiras\n", "droite\n", "droite\n", "avance\n", 
									 "pose phiras\n", "droite\n", "droite\n", "broadcast hello\n", "avance\n", "prend nourriture\n", "prend nourriture\n", "droite\n", 
									 "droite\n", "avance\n", "pose thystame\n", "incantation\n"};
	int					i;
	
	nb = 0;
	i = 0;
	buf = (char*)malloc(1000);
	if (argc < 5 || argc > 7 || !cl_parse_line(argc, argv, &addr, &port, &team))
		return (cl_err_usage());
	cout << "client here ! " << endl;
	team = strcat(team, "\n");
	sock = cl_new_connection(addr, port, team);
	recv(sock, buf, 1023, 0);
	cout << "First " << buf << endl;
/*	if (fork())
	{
		sleep(3);
		sock = cl_new_connection(argv[1], argv[2], team);
	}
*/	do
	{
		nb++;
		cout << nb <<endl;
		cl_calcul(buf, sock, tab_cmd, i);
		cout << "end" << endl;
		i++;
	} while (strcmp(buf, "mort\n") && i < 53);
	return (0);
}
