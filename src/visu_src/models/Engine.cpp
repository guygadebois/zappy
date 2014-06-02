// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Engine.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2014/05/31 14:10:28 by glourdel          #+#    #+#             //
//   Updated: 2014/06/02 16:51:55 by glourdel         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Engine.h"

#include <iostream>
using namespace std;

Engine::Engine()
{
	SKeyMap	keyMap[5];

	m_device = createDevice(video::EDT_OPENGL,
							core::dimension2d<u32>(2560, 1440),
							32, true, true, false, 0);
	m_device->getCursorControl()->setVisible(false);
#ifdef _IRR_OSX_PLATFORM_
	m_device->getFileSystem()->changeWorkingDirectoryTo ("visu.app");
	m_device->getFileSystem()->changeWorkingDirectoryTo ("Contents");
	m_device->getFileSystem()->changeWorkingDirectoryTo ("Resources");
#endif
	m_driver = m_device->getVideoDriver();
	m_sceneManager = m_device->getSceneManager();
	keyMap[0].Action = EKA_MOVE_FORWARD;  // avancer
	keyMap[0].KeyCode = KEY_KEY_W;        // w
	keyMap[1].Action = EKA_MOVE_BACKWARD; // reculer
	keyMap[1].KeyCode = KEY_KEY_S;        // s
	keyMap[2].Action = EKA_STRAFE_LEFT;   // a gauche
	keyMap[2].KeyCode = KEY_KEY_A;        // a
	keyMap[3].Action = EKA_STRAFE_RIGHT;  // a droite
	keyMap[3].KeyCode = KEY_KEY_D;        // d
	keyMap[4].Action = EKA_JUMP_UP;       // saut
	keyMap[4].KeyCode = KEY_SPACE;        // barre espace
	m_sceneManager->addCameraSceneNodeFPS(0, 100.0f, 0.1f, -1, keyMap, 5);
	m_trentorMesh = m_sceneManager->getMesh("models/faerie/Faerie.x");
	m_planetMesh = m_sceneManager->getMesh("models/earth/earth.x");
}

Engine::~Engine()
{
	m_device->drop();
}

bool	Engine::addPlanet()
{
	if (m_planetMesh == NULL)
		return (false);
	m_planet = m_sceneManager->addAnimatedMeshSceneNode(m_planetMesh);
	if (m_planet == NULL)
		return (false);
	m_planet->setScale(core::vector3df(2.0f));
	m_planet->setMaterialFlag(video::EMF_LIGHTING, false);
	m_planet->setMaterialFlag(video::EMF_ANTI_ALIASING, true);
	m_planet->setMaterialFlag(video::EMF_ANISOTROPIC_FILTER, true);
	return (true);
}

bool	Engine::addTrantors()
{
	if (m_trentorMesh == NULL)
		return (false);
	m_trentor1 = m_sceneManager->addAnimatedMeshSceneNode(m_trentorMesh);
	if (m_trentor1 == NULL)
		return (false);
	m_trentor1->setMaterialFlag(video::EMF_LIGHTING, false);
	m_trentor1->setMaterialFlag(video::EMF_ANTI_ALIASING, true);
	m_trentor1->setMaterialFlag(video::EMF_ANISOTROPIC_FILTER, true);
	m_trentor1->setMaterialType(video::EMT_TRANSPARENT_ALPHA_CHANNEL_REF);
	m_trentor1->setPosition(core::vector3df(0.0f, 5.0f, 0));
}

void	Engine::loop()
{
	while(m_device->run())
	{
		m_driver->beginScene (true, true,
							  video::SColor(255, 0, 0, 0));
		m_sceneManager->drawAll();
		m_driver->endScene();
	}
}
