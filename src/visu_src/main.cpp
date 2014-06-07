// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2014/05/28 11:59:19 by glourdel          #+#    #+#             //
//   Updated: 2014/06/07 22:18:49 by glourdel         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <irrlicht.h>
#include <iostream>
#include "MapData.h"
#include "Engine.h"
#include "visu_define.h"

using namespace std;

int			main(void)
{
	MapData	mapData(40, 20);
	Engine	engine(&mapData);

	if (engine.addPlanet()
		&& engine.addTrantor(1, 0, 0, WEST, 1, "les Toto")
		&& engine.addTrantor(2, 0, 1, EAST, 1, "les Toto")
//&& engine.addTrees()
		&& engine.addRocks() && engine.addLights())
		engine.loop();
	else
		cout << "Failed before engine loop" << endl;
	return (0);
}
