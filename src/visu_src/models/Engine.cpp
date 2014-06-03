// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Engine.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2014/05/31 14:10:28 by glourdel          #+#    #+#             //
//   Updated: 2014/06/03 16:51:17 by glourdel         ###   ########.fr       //
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
	m_treeMesh = m_sceneManager->getMesh("models/tree/palm_tree.obj");
	m_planetTexture = m_driver->getTexture("textures/grass.jpg");
}

Engine::~Engine()
{
	m_device->drop();
}

bool	Engine::addPlanet()
{
	m_planet = m_sceneManager->addSphereSceneNode(PLANET_RADIUS, 56, 0, -1,
												  core::vector3df(0, -25, 120));
	if (m_planet == NULL)
		return (false);
	m_planet->setMaterialFlag(video::EMF_LIGHTING, false);
	m_planet->setMaterialFlag(video::EMF_ANTI_ALIASING, true);
	m_planet->setMaterialFlag(video::EMF_ANISOTROPIC_FILTER, true);
	m_planet->setMaterialTexture(0, m_planetTexture);
// Create parent node tha will be cloned for each object
	m_emptyParent = m_sceneManager->addSphereSceneNode(1.0f, 6, m_planet);
	m_emptyParent->setRotation(core::vector3df(0.0f, 180.0f, 0.0f));

// Draw the grid :

	video::IImage	*img;
	video::ITexture* texture;

	img = m_driver->createImage(video::ECF_A8R8G8B8, core::dimension2d<u32>(4000, 2000));
	if (img)
	{
		for(int i = 0; i < 4000; i++)
		{
			for(int j = 0; j < 2000; j++)
			{
				if (j < 500 || j >= 1500)
					img->setPixel(i, j, video::SColor(255, 255, 55, 55));
				else if (i % 50 == 0 || j % 50 == 0)
					img->setPixel(i, j, video::SColor(255, 255, 255, 255));
				else
					img->setPixel(i, j, video::SColor(255, 0, 0, 0));
			}
		}
		texture = m_driver->addTexture("grid", img);
		texture->grab();
		m_planet->setMaterialTexture(0, texture);
		texture->drop();
		img->drop();
	}

// Skybox

	scene::ISceneNode* skybox;

	if ((skybox = m_sceneManager->addSkyBoxSceneNode(
			 m_driver->getTexture("textures/sky_up.jpg"),
			 m_driver->getTexture("textures/sky_dn.jpg"),
			 m_driver->getTexture("textures/sky_lf.jpg"),
			 m_driver->getTexture("textures/sky_rt.jpg"),
			 m_driver->getTexture("textures/sky_ft.jpg"),
			 m_driver->getTexture("textures/sky_bk.jpg"))))
		skybox->setVisible(true);
	return (true);
}

bool	Engine::addTrantors()
{
	scene::ISceneNode				*parent;

	if (m_trentorMesh == NULL || (parent = m_emptyParent->clone()) == NULL)
		return (false);
	m_trentor1 = m_sceneManager->addAnimatedMeshSceneNode(m_trentorMesh, parent);
	m_trentor1->setPosition(core::vector3df(0, PLANET_RADIUS, 0));
	if (m_trentor1 == NULL)
		return (false);
	m_trentor1->setAnimationSpeed(5);
	m_trentor1->setFrameLoop(40, 45);
	m_trentor1->setMaterialFlag(video::EMF_LIGHTING, false);
	m_trentor1->setMaterialFlag(video::EMF_ANTI_ALIASING, true);
	m_trentor1->setMaterialFlag(video::EMF_ANISOTROPIC_FILTER, true);
	m_trentor1->setMaterialType(video::EMT_TRANSPARENT_ALPHA_CHANNEL_REF);
	return (true);
}

bool	Engine::addTrees(MapData *mapData)
{
	scene::IAnimatedMeshSceneNode	*tree;
	scene::ISceneNode				*parent;

	if (m_treeMesh == NULL)
		return (false);
	// for (int i = 0; i < 15; i++)
	// {
	// 	if ((parent = m_emptyParent->clone()) == NULL)
	// 		return (false);
	// 	tree = m_sceneManager->addAnimatedMeshSceneNode(m_treeMesh, parent);
	// 	tree->setMaterialFlag(video::EMF_LIGHTING, false);
	// 	tree->setPosition(core::vector3df(0, PLANET_RADIUS, 0));
	// 	parent->setRotation(core::vector3df(0, 0, -i * 10 - 10));
	// }
	for (int i = 0; i < mapData->getGridSize().Width; i++)
	{
		for (int j = 0; j < mapData->getGridSize().Height; j++)
		{
			if ((parent = m_emptyParent->clone()) == NULL)
			{
				cout << "Parent clone failed..." << endl;
				return (false);
			}
			tree = m_sceneManager->addAnimatedMeshSceneNode(m_treeMesh, parent);
			tree->setMaterialFlag(video::EMF_LIGHTING, false);
			tree->setPosition(core::vector3df(
								  mapData->m_matrix[i][j].middle.X,
								  mapData->m_matrix[i][j].middle.Y,
								  mapData->m_matrix[i][j].middle.Z));
		}
	}
	return (true);
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
