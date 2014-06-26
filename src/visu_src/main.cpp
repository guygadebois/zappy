// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2014/05/28 11:59:19 by glourdel          #+#    #+#             //
//   Updated: 2014/06/26 10:51:27 by glourdel         ###   ########.fr       //
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
//	engine->addTrantor(42, 39, 1, NORTH, 1, "42");
	engine->loop(&visuComm);
	delete (engine);
	delete (mapData);
	return (0);
}
