// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2014/05/28 11:59:19 by glourdel          #+#    #+#             //
//   Updated: 2014/06/11 13:43:37 by glourdel         ###   ########.fr       //
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
//		&& engine->updateTrantorPosition("pnw 5 0 4 SOUTH")
//&& engine->addTrees()
		&& engine->addLights())
		engine->loop();
	else
		cout << "Failed before engine loop" << endl;
	delete (mapData);
	delete (engine);
	return (0);
}
