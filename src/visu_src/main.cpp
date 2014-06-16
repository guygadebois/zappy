// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2014/05/28 11:59:19 by glourdel          #+#    #+#             //
//   Updated: 2014/06/16 14:10:14 by glourdel         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <irrlicht.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "MapData.h"
#include "Engine.h"
#include "visu_define.h"

using namespace std;

// static bool	getMapData(MapData **mapData)
// {
// 	while (42)
// 	{
// 		if (//receive grid size
// 			)
// 		{
// 			mapData = new MapData(40, 20);
// 			break ;
// 		}
// 	}
// 	while (mapData->isReady() == false)
// 	{
// 		//receive datas
// 	}
// 	return (true);
// }

int			main(void)
{
	MapData	*mapData;
	Engine	*engine;

	srand(time(NULL));
//connect and send "GRAPHIC\n"
//	if (!getMapData(&mapData))
//		return (1);
	mapData = new MapData(40, 20);
	engine = new Engine(mapData);
	if (engine->addPlanet()
		&& engine->newClientConnected("pnw 1 0 1 2 1 toto")
		&& engine->newClientConnected("pnw 2 0 2 1 1 tota")
		&& engine->newClientConnected("pnw 3 0 3 1 1 toto")
		&& engine->newClientConnected("pnw 4 0 4 1 1 toti")
		&& engine->newClientConnected("pnw 5 0 5 1 1 toto")
		&& engine->newClientConnected("pnw 6 0 6 1 1 totu")
		&& engine->newClientConnected("pnw 7 0 7 1 1 toto")
		&& engine->newClientConnected("pnw 8 0 8 1 1 toto")
		&& engine->updateTrantorLevel("plv 2 8")
		&& engine->setSquareContent("bct 0 2 3 1 1 1 1 1 1")
		&& engine->updateTrantorPosition("pnw 5 5 4 2")
		&& engine->takeRessource("pgt 2 2")
		&& engine->broadcast("pbc 1 Coucou")
		&& engine->addLights())
		engine->loop();
	else
		cout << "Failed before engine loop" << endl;
	delete (mapData);
	delete (engine);
	return (0);
}
