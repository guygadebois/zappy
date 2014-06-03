// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2014/05/28 11:59:19 by glourdel          #+#    #+#             //
//   Updated: 2014/06/03 16:56:08 by glourdel         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <irrlicht.h>
#include <iostream>
#include "MapData.h"
#include "Engine.h"

using namespace std;

int			main(void)
{
	MapData	mapData(40, 20);
	Engine	engine(&mapData);

	if (engine.addPlanet() && engine.addTrantors() && engine.addTrees())
		engine.loop();
	else
		cout << "Failed before engine loop" << endl;
	return (0);
}
