// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2014/05/28 11:59:19 by glourdel          #+#    #+#             //
/*   Updated: 2014/06/17 14:08:31 by dcouly           ###   ########.fr       */
//                                                                            //
// ************************************************************************** //

#include <irrlicht.h>
#include <iostream>
#include <stdlib.h>
#include <netdb.h>
#include <time.h>
#include <unistd.h>
#include <sys/select.h>
#include "MapData.h"
#include "Engine.h"
#include "common.h"
#include "mystring.h"
#include "visu_define.h"

using namespace std;

size_t     find_ret(string str)
{
	size_t	found;

	found = str.find("\n");
	return (found);
}

string  getCmdBuf(string *buf)
{
	size_t	nb_char;
	string	cmd;

	if ((nb_char = find_ret(*buf)))
	{
		cmd = *buf;
		cmd.resize(nb_char);
		*buf = buf->substr(nb_char + 1, buf->size() - nb_char - 1);
		return (cmd);
	}
	return ("");
}


MapData *setMap(const string line)
{
	vector<string>	*tokens;
	MapData			*map;

	tokens = mystring::strsplit(line);
	map = new MapData(stoi((*tokens)[1]), stoi((*tokens)[2]));
	delete(tokens);
	return (map);
}

static bool	getMapData(int sock, MapData **mapData)
{
	char			buf[1024];
	string			cmd;
	string			tmp;
	string			cmd2;
	fd_set			read_fd;
	fd_set			write_fd;
	int				nb_char;

	cmd = "";
 	while (42)
 	{
		FD_ZERO(&read_fd);
		FD_SET(sock, &read_fd);
		FD_ZERO(&write_fd);
		FD_SET(1, &write_fd);
		if (select(sock + 1, &(read_fd), &(write_fd), NULL, NULL) == -1)
		{
			cout << "Error Select" << endl;
			return (false);
		}
		if (FD_ISSET(sock, &read_fd))
		{
		 	nb_char = recv(sock, buf, 1023, 0);
			buf[nb_char] = 0;
			tmp = strdup(buf);
			cmd = cmd + tmp;
			cout << cmd << endl;
 			if ((cmd2 = getCmdBuf(&cmd)) != "")
	 		{
 				*mapData = setMap(cmd2);
				break ;
 			}
		}
	}
	cmd2 = getCmdBuf(&cmd);
	cout << cmd << endl;
 	while ((*mapData)->isReady() == false)
 	{
		FD_ZERO(&read_fd);
		FD_SET(sock, &read_fd);
		FD_ZERO(&write_fd);
		FD_SET(1, &write_fd);
		if (select(sock + 1, &(read_fd), &(write_fd), NULL, NULL) == -1)
		{
			cout << "Error Select" << endl;
			return (false);
		}
		if (FD_ISSET(sock, &read_fd))
		{
		 	nb_char = recv(sock, buf, 1023, 0);
			buf[nb_char] = 0;
			tmp = strdup(buf);
			cmd = cmd + tmp;
		}
/*		if ((cmd2 = getCmdBuf(&cmd)) != "")
			(mapData)->setSquareContent(cmd2);
*/		sleep(1);
 	}
	return (true);
}

int			main(int argc, char **argv)
{
//	Engine	*engine;
	int		sock;
	MapData	*mapData;

	if (argc != 3)
		return (1);
	srand(time(NULL));
	sock = cl_new_connection(argv[1], argv[2], (char*)"GRAPHIC\n");
	if (!getMapData(sock, &mapData))
		return (1);
//	engine = new Engine(mapData);
/*	if (engine->addPlanet()

		&& engine->addTrantor(1, 0, 0, EAST, 1, "1")
		&& engine->addTrantor(2, 0, 1, EAST, 1, "2")
		&& engine->addTrantor(3, 0, 2, EAST, 1, "3")
		&& engine->addTrantor(4, 0, 3, EAST, 1, "4")
		&& engine->addTrantor(5, 0, 4, EAST, 1, "5")
		&& engine->addTrantor(6, 0, 5, EAST, 1, "6")
		&& engine->addTrantor(7, 0, 6, EAST, 1, "7")
		&& engine->addTrantor(8, 0, 7, EAST, 1, "8")
		&& engine->addTrantor(9, 0, 8, EAST, 1, "9")
		&& engine->addTrantor(10, 0, 9, EAST, 1, "10")
		&& engine->setSquareContent("bct 1 1 3 1 1 1 1 1 1")
		&& engine->updateTrantorPosition("pnw 5 5 4 4")
//		&& engine->addTrees()
		&& engine->addLights())
		engine->loop();
	delete (engine);
*/
	while(1)
	{
		sleep(1);
		cout << "ok\n" << endl;
	}
	return (0);
}
