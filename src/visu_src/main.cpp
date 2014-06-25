// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2014/05/28 11:59:19 by glourdel          #+#    #+#             //
//   Updated: 2014/06/25 22:45:25 by glourdel         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <irrlicht.h>
#include <iostream>
#include <stdlib.h>
#include "MapData.h"
#include "Engine.h"
#include "common.h"
#include "mystring.h"
#include "visu_define.h"
#include "VisuComm.h"

using namespace std;

int			main(int argc, char **argv)
{
	Engine	*engine = NULL;
	int		sock;
	MapData	*mapData;

	if (argc != 3)
	{
		cerr << "Usage: visu <hostname> <port>" << endl;
		return (1);
	}
	srand(time(NULL));
	sock = cl_new_connection(argv[1], argv[2], (char*)"GRAPHIC\n");

	VisuComm	visuComm(mapData, engine, sock);
	if (!visuComm.getMapData())
		return (1);
	// engine->addTrantor(42, 44, 16, NORTH, 1, "42");
	// engine->treatCmd("ppo 42 44 15 1");
	// engine->treatCmd("ppo 42 44 14 1");
	// engine->treatCmd("ppo 42 44 13 1");
	// engine->treatCmd("ppo 42 44 12 1");
	// engine->treatCmd("ppo 42 44 11 1");
	// engine->treatCmd("ppo 42 44 10 1");
	// engine->treatCmd("ppo 42 44 9 1");
	// engine->treatCmd("ppo 42 44 8 1");
	// engine->treatCmd("ppo 42 44 7 1");
	// engine->treatCmd("ppo 42 44 6 1");
	// engine->treatCmd("ppo 42 44 5 1");
	// engine->treatCmd("ppo 42 44 4 1");
	// engine->treatCmd("ppo 42 44 3 1");
	// engine->treatCmd("ppo 42 44 2 1");
	// engine->treatCmd("ppo 42 44 1 1");
	// engine->treatCmd("ppo 42 44 0 1");
	// engine->treatCmd("ppo 42 44 24 1");
	// engine->addTrantor(2, 0, 2, EAST, 1, "2");
	// engine->addTrantor(3, 0, 4, EAST, 1, "3");
	// engine->addTrantor(4, 0, 6, EAST, 1, "4");
	// engine->addTrantor(5, 0, 8, WEST, 1, "5");
	// 	&& engine->addTrantor(6, 0, 5, EAST, 1, "6")
	// 	// && engine->addTrantor(7, 0, 6, EAST, 1, "7")
	// 	// && engine->addTrantor(8, 0, 7, EAST, 1, "8")
	// 	// && engine->addTrantor(9, 0, 8, EAST, 1, "9")
	// 	// && engine->addTrantor(10, 0, 9, EAST, 1, "10")
	// 	&& engine->broadcast("pcb 2 toto")
	// 	&& engine->die("pdi 1")
	// 	&& engine->treatCmd("pfk 6")
	// 	&& engine->treatCmd("enw 42 6 0 5")
	// 	&& engine->treatCmd("ppo 6 2 5 2")
	// 	&& engine->treatCmd("eht 42")
	// 	&& engine->treatCmd("pic 0 2 2 2 3 4 5"))
	engine->loop(&visuComm);
	delete (engine);
	delete (mapData);
	return (0);
}
