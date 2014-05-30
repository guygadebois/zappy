// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2014/05/28 11:59:19 by glourdel          #+#    #+#             //
//   Updated: 2014/05/30 22:28:30 by glourdel         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include "irrlicht.h"

using namespace std;

int			main(void)
{
	cout << "visu here !" << endl;
	irr::IrrlichtDevice *device = irr::createDevice (
		irr::video::EDT_OPENGL,
		irr::core::dimension2d<irr::u32>(800,600),
		32,
		false,
		true,
		false,
		0);
	irr::video::IVideoDriver* driver = device->getVideoDriver();
	irr::scene::ISceneManager *sceneManager = device->getSceneManager();
	sceneManager->addCameraSceneNode(0,
									 irr::core::vector3df (0,0,0),
									 irr::core::vector3df (5,0,0));
	while(device->run())
	{
		driver->beginScene (true, true,
							irr::video::SColor(255, 255, 255, 255));
		sceneManager->drawAll();
		driver->endScene();
	}
	device->drop();
	return (0);
}
