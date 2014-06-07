// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Engine.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2014/05/31 14:10:28 by glourdel          #+#    #+#             //
//   Updated: 2014/06/07 18:10:14 by glourdel         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include "Engine.h"
#include "MySceneNode.h"

using namespace std;

Engine::Engine(MapData *mapData) : m_mapData(mapData)
{
	SKeyMap	keyMap[5];

	m_device = createDevice(video::EDT_OPENGL,
#ifdef __IRR_OSX_PLATFORM__
							core::dimension2d<u32>(2560, 1440),
#else
							core::dimension2d<u32>(1920, 1081),
#endif
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
	m_camera = m_sceneManager->addCameraSceneNodeFPS(0, 100.0f, 0.1f, -1, keyMap, 5);
	m_camera->setPosition(core::vector3df(0.0f, 200.0f, 300.0f));
	m_camera->setRotation(m_camera->getRotation() + core::vector3df(20.0f, 0.0f, 0.0f));
	m_trentorMesh = m_sceneManager->getMesh("models/faerie/Faerie.x");
	m_treeMesh = m_sceneManager->getMesh("models/tree/palm_tree.obj");
	m_rockMesh[0] = m_sceneManager->getMesh("models/Iso_3DS/cube.3ds");
	m_rockMesh[1] = m_sceneManager->getMesh("models/Iso_3DS/deltoid_dodec.3ds");
	m_rockMesh[2] = m_sceneManager->getMesh("models/Iso_3DS/hexoctahedron.3ds");
	m_rockMesh[3] = m_sceneManager->getMesh("models/Iso_3DS/hextetrahedron.3ds");
	m_rockMesh[4] = m_sceneManager->getMesh("models/Iso_3DS/rhombic_dodec.3ds");
	m_rockMesh[5] = m_sceneManager->getMesh("models/Iso_3DS/trapezohedron.3ds");
	m_planetTexture = m_driver->getTexture("textures/grass.jpg");
}

Engine::~Engine(void)
{
	m_device->drop();
}

bool	Engine::addPlanet(void)
{
	m_planet = m_sceneManager->addSphereSceneNode(PLANET_RADIUS, 36, 0, -1);
	if (m_planet == NULL)
		return (false);
//	m_planet->setMaterialFlag(video::EMF_LIGHTING, false);
	m_planet->setMaterialTexture(0, m_planetTexture);

// Create parent node tha will be cloned for each object
	m_emptyParent = new scene::MySceneNode(m_planet, m_sceneManager, m_mapData);
	m_emptyParent->drop();

// Draw the grid :
	video::IImage	*img;
	video::ITexture* texture;

	img = m_driver->createImage(video::ECF_A8R8G8B8, core::dimension2d<u32>(4000, 2000));
	if (img)
	{
		for(u32 i = 0; i < 4000; i++)
		{
			for(u32 j = 0; j < 2000; j++)
			{
				if (j < m_mapData->getTexturePSize().Height / 4
					|| j >= m_mapData->getTexturePSize().Height / 4 * 3)
					img->setPixel(i, j, video::SColor(255, 255, 55, 55));
				else if (i % m_mapData->getGridElemPSize().Width == 0
						 || j % m_mapData->getGridElemPSize().Height == 0)
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

bool	Engine::addTrantor()
{
	scene::MySceneNode	*parent;

	if (m_trentorMesh == NULL || (parent = m_emptyParent->clone()) == NULL)
		return (false);
	if (parent->init(m_trentorMesh, TRANTOR, core::vector2di(0, 3), 1, 1, EAST, "Super team"))
		return (true);
	return (false);
}

bool	Engine::addTrees(void)
{
	scene::MySceneNode	*parent;

	if (m_treeMesh == NULL)
		return (false);
	for (u32 i = 0; i < m_mapData->getGridSize().Width; i++)
	{
		for (u32 j = 0; j < m_mapData->getGridSize().Height; j++)
		{
			if ((parent = m_emptyParent->clone()) == NULL)
			{
				cout << "Parent clone failed..." << endl;
				return (false);
			}
			parent->init(m_treeMesh, TREE);
			parent->moveToSquare(i, j, 0.5f, 0.5f, 0.1f);
		}
	}
	return (true);
}

bool	Engine::addRocks(void)
{
	scene::MySceneNode				*parent;
	scene::IAnimatedMeshSceneNode	*son;
	char							path[][24] = {
		"textures/blue-green.png",
		"textures/yellow.png",
		"textures/violet.png",
		"textures/green.png",
		"textures/transp.png",
		"textures/red.png"
	};

	for (u8 i = 0; i < 6; ++i)
	{
		if (m_rockMesh[i] == NULL)
			return (false);
	}
	for (u32 i = 0; i < m_mapData->getGridSize().Width; i++)
	{
		for (u32 j = 0; j < m_mapData->getGridSize().Height; j++)
		{
			if ((parent = m_emptyParent->clone()) == NULL)
			{
				cout << "Parent clone failed..." << endl;
				return (false);
			}
			if ((son = parent->init(m_rockMesh[i % 6], STONE)))
			{
				son->setMaterialTexture(0, m_driver->getTexture(path[i % 6]));
				parent->moveToSquare(i, j, 0.5f, 0.5f, 0.1f);
			}
		}
	}
	return (true);
}

bool	Engine::addLights(void)
{
	scene::ILightSceneNode	*light;

	m_sceneManager->setAmbientLight(irr::video::SColorf(0.3f, 0.3f, 0.3f, 0.0f));
	light = m_sceneManager->addLightSceneNode(0,
						  irr::core::vector3df(100, 300, 300),
						  irr::video::SColorf(0.4f, 0.4f, 0.6f, 0.0f), 10000.0f);
	light->getLightData().SpecularColor = irr::video::SColorf(0.5, 0.5, 0.5, 0.5);
	return (true);
}

void	Engine::loop(void)
{
	while(m_device->run())
	{
		m_driver->beginScene (true, true,
							  video::SColor(255, 0, 0, 0));
		m_mapData->checkAnimationsEnd();
		m_sceneManager->drawAll();
		m_driver->endScene();
	}
}
