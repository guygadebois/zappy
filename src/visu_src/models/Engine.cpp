// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Engine.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2014/05/31 14:10:28 by glourdel          #+#    #+#             //
//   Updated: 2014/06/26 11:50:55 by glourdel         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <stdlib.h>
#include "Engine.h"
#include "MySceneNode.h"
#include "VisuComm.h"
#include "errors.h"

using namespace std;

Engine::Engine(MapData *mapData, VisuComm *visuComm)
	: m_device(NULL),
	  m_driver(NULL),
	  m_sceneManager(NULL),
	  m_camera(NULL),
	  m_mapData(mapData),
	  m_visuComm(visuComm),
	  m_started(false),
	  m_emptyParent(NULL),
	  m_planet(NULL),
	  m_trentorMesh(NULL),
	  m_treeMesh(NULL),
	  m_planetTexture(NULL),
	  m_sunTexture(NULL),
	  m_planetGrid(NULL),
	  m_gui(NULL)
{
	SKeyMap	keyMap[5];

	m_device = createDevice(video::EDT_OPENGL,
#ifdef __IRR_OSX_PLATFORM__
							core::dimension2d<u32>(2560, 1441),
#else
							core::dimension2d<u32>(1920, 1081),
#endif
							32, true, true, false, 0);
	m_device->getCursorControl()->setVisible(false);
#ifdef _IRR_OSX_PLATFORM_
	m_device->getFileSystem()->changeWorkingDirectoryTo("visu.app");
	m_device->getFileSystem()->changeWorkingDirectoryTo("Contents");
	m_device->getFileSystem()->changeWorkingDirectoryTo("Resources");
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
	m_eggMesh = m_sceneManager->getMesh("models/egg.3DS");
	m_itemMesh[0] = m_sceneManager->getMesh("models/fourmis/formica rufa 17384.3ds");
	m_itemMesh[1] = m_sceneManager->getMesh("models/Iso_3DS/cube.3ds");
	m_itemMesh[2] = m_sceneManager->getMesh("models/Iso_3DS/deltoid_dodec.3ds");
	m_itemMesh[3] = m_sceneManager->getMesh("models/Iso_3DS/hexoctahedron.3ds");
	m_itemMesh[4] = m_sceneManager->getMesh("models/Iso_3DS/hextetrahedron.3ds");
	m_itemMesh[5] = m_sceneManager->getMesh("models/Iso_3DS/rhombic_dodec.3ds");
	m_itemMesh[6] = m_sceneManager->getMesh("models/Iso_3DS/trapezohedron.3ds");
	for (u8 i = 0; i < 7; i++)
		m_itemMesh[i]->setHardwareMappingHint(scene::EHM_STATIC);
	m_planetTexture = m_driver->getTexture("textures/grass.jpg");
	m_sunTexture = m_driver->getTexture("textures/sun.bmp");
	m_gemTexture[0] = m_driver->getTexture("textures/blue-green.png");
	m_gemTexture[1] = m_driver->getTexture("textures/yellow.png");
	m_gemTexture[2] = m_driver->getTexture("textures/violet.png");
	m_gemTexture[3] = m_driver->getTexture("textures/green.png");
	m_gemTexture[4] = m_driver->getTexture("textures/transp.png");
	m_gemTexture[5] = m_driver->getTexture("textures/red.png");
	m_trantorTexture[0] = m_driver->getTexture("models/faerie/FaerieA_Skin.jpg");
	m_trantorTexture[1] = m_driver->getTexture("models/faerie/FaerieB_Skin.jpg");
	m_trantorTexture[2] = m_driver->getTexture("models/faerie/FaerieC_Skin.jpg");
	m_trantorTexture[3] = m_driver->getTexture("models/faerie/FaerieD_Skin.jpg");
	m_trantorTexture[4] = m_driver->getTexture("models/faerie/FaerieE_Skin.jpg");
	m_trantorTexture[5] = m_driver->getTexture("models/faerie/FaerieF_Skin.jpg");
	m_trantorTexture[6] = m_driver->getTexture("models/faerie/FaerieG_Skin.jpg");
	m_trantorTexture[7] = m_driver->getTexture("models/faerie/FaerieH_Skin.jpg");
	m_trantorTexture[8] = m_driver->getTexture("models/faerie/FaerieI_Skin.jpg");
	m_trantorTexture[9] = m_driver->getTexture("models/faerie/FaerieJ_Skin.jpg");
	m_particleTexture1 = m_driver->getTexture("textures/particle.png");
	m_particleTexture2 = m_driver->getTexture("textures/particle2.png");
	m_particleTexture3 = m_driver->getTexture("textures/particle3.png");
	m_gui = m_device->getGUIEnvironment();
	m_gui->getSkin()->setFont(m_gui->getFont("fonts/fontlucida.png"), irr::gui::EGDF_DEFAULT);
	addPlanet();
	addLights();
}

Engine::~Engine(void)
{
	m_device->drop();
}

bool	Engine::start(void)
{
	m_started = true;
	return (true);
}

bool	Engine::isStarted(void) const
{
	return (m_started);
}

bool	Engine::addPlanet(void)
{
	scene::ISceneNode	*center;

	center = m_sceneManager->addSphereSceneNode(1, 36, 0, -1);
	m_planet = m_sceneManager->addSphereSceneNode(PLANET_RADIUS, 36, 0, -1);
	if (m_planet == NULL)
		return (false);
	m_planet->setRotation(core::vector3df(0.0f, -90.0f, 0.0f));
	m_planet->setMaterialTexture(0, m_planetTexture);

// Create parent node that will be cloned for each object
	m_emptyParent = new scene::MySceneNode(center, m_sceneManager, m_mapData);
	m_emptyParent->drop();

// Draw the grid :
	video::IImage			*img;
	video::ITexture*		texture;
	core::dimension2d<u32>	texturePSize;

	texturePSize = m_mapData->getTexturePSize();
	img = m_driver->createImage(video::ECF_A8R8G8B8,
								core::dimension2d<u32>(texturePSize.Width, texturePSize.Height));
	if (img)
	{
		for (u32 i = 0; i < texturePSize.Width; i++)
		{
			for (u32 j = 0; j < texturePSize.Height; j++)
			{
				if (j < static_cast<f32>(texturePSize.Height) / 4.0f
					|| j >= static_cast<f32>(texturePSize.Height) / 4.0f * 3.0f)
					img->setPixel(i, j, video::SColor(0, 0, 50, 0));
				else if (i % m_mapData->getGridElemPSize().Width == 0
						 || static_cast<u32>(j - static_cast<f32>(texturePSize.Height) / 4.0f) % m_mapData->getGridElemPSize().Height == 0)
					img->setPixel(i, j, video::SColor(255, 255, 255, 255));
				else
					img->setPixel(i, j, video::SColor(255, 25, 155, 55));
			}
		}
		texture = m_driver->addTexture("grid", img);
		texture->grab();
		m_driver->makeColorKeyTexture(texture, video::SColor(0,0,0,0));
		m_planet->setMaterialTexture(0, texture);
		texture->drop();
		img->drop();
	}

// Portal Particles :

	scene::IParticleSystemSceneNode		*partSys;
	scene::IParticleSystemSceneNode		*partSys2;
	scene::IParticleCylinderEmitter		*emitter;
	scene::IParticleAffector			*affector;

	partSys = m_sceneManager->addParticleSystemSceneNode(false);
	emitter = partSys->createCylinderEmitter(
		core::vector3df(0.0f, PLANET_RADIUS - 3.0f, 0.0f),        // centre
		20.0f,
		core::vector3df(0.0f, 20.0f, 0.0f),
		20.0f,
		true,
		core::vector3df(0.0f, -0.1f, 0.0f),
		8000, 10000,                                       // nb particules emises a la sec min / max
		irr::video::SColor(0,0,0,0),                  // couleur la plus sombre
		irr::video::SColor(0,255,255,255),            // couleur la plus claire
		6000, 10000,                                    // duree de vie min / max
		0,                                            // angle max d'ecart / direction prevue
		irr::core::dimension2df(1.8f, 1.8f),           // taille minimum
		irr::core::dimension2df(2.6f, 2.6f));          // taille maximum

	partSys->setEmitter(emitter);
	emitter->drop();
	affector = partSys->createGravityAffector();
	partSys->addAffector(affector);
	affector->drop();

	partSys2 = m_sceneManager->addParticleSystemSceneNode(false);
	emitter = partSys2->createCylinderEmitter(
		core::vector3df(0.0f, -PLANET_RADIUS + 3.0f, 0.0f),        // centre
		20.0f,
		core::vector3df(0.0f, -20.0f, 0.0f),
		20.0f,
		true,
		core::vector3df(0.0f, 0.1f, 0.0f),
		8000, 10000,                                       // nb particules emises a la sec min / max
		irr::video::SColor(0,0,0,0),                  // couleur la plus sombre
		irr::video::SColor(0,255,255,255),            // couleur la plus claire
		6000, 10000,                                    // duree de vie min / max
		0,                                            // angle max d'ecart / direction prevue
		irr::core::dimension2df(1.8f, 1.8f),           // taille minimum
		irr::core::dimension2df(2.6f, 2.6f));          // taille maximum

	partSys2->setEmitter(emitter);
	emitter->drop();
	affector = partSys2->createGravityAffector(core::vector3df(0.0f, 0.03f, 0.0f));
	partSys2->addAffector(affector);
	affector->drop();

	if (m_particleTexture3)
	{
//		m_driver->makeColorKeyTexture(m_particleTexture3, video::SColor(0,0,0,0));
		partSys->setMaterialTexture(0, m_particleTexture3);
		partSys2->setMaterialTexture(0, m_particleTexture3);
	}
	partSys->setMaterialFlag(video::EMF_ZWRITE_ENABLE, false);
	partSys->setMaterialType(video::EMT_TRANSPARENT_ADD_COLOR);
	partSys2->setMaterialFlag(video::EMF_ZWRITE_ENABLE, false);
	partSys2->setMaterialType(video::EMT_TRANSPARENT_ADD_COLOR);


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

bool	Engine::addTrantor(int id, u32 X, u32 Y, u8 orientation, u8 level,
						   const string team)
{
	scene::MySceneNode				*parent;
	u32								teamNbr;

	if (m_trentorMesh == NULL || (parent = m_emptyParent->clone()) == NULL)
		return (false);
	if (parent->init(m_trentorMesh, TRANTOR, core::vector2di(X, Y), id, level,
					 orientation, team))
	{
		teamNbr = parent->getTeamNbr();
		parent->setTexture(m_trantorTexture[teamNbr % 10]);
		parent->placeOnSquare(X, Y, (float)rand() / RAND_MAX, (float)rand() / RAND_MAX);
		return (true);
	}
	return (false);
}

bool	Engine::addEgg(int id, u32 X, u32 Y, f32 offsetX, f32 offsetY,
					   const string team)
{
	scene::MySceneNode				*parent;
	u32								teamNbr;

	if (m_eggMesh == NULL || (parent = m_emptyParent->clone()) == NULL)
		return (false);
	if (parent->init(m_eggMesh, EGG, core::vector2di(X, Y), id, 1,
					 SOUTH, team))
	{
		teamNbr = parent->getTeamNbr();
		parent->setTexture(m_trantorTexture[teamNbr % 10]);
		parent->placeOnSquare(X, Y, offsetX, offsetY);
		return (true);
	}
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

bool	Engine::addLights(void)
{
	scene::IMeshSceneNode		*parent;
	scene::IMeshSceneNode		*sun;
	scene::ILightSceneNode		*light;
	scene::ISceneNodeAnimator	*animator;

	parent = m_sceneManager->addSphereSceneNode(2, 6, 0, -1);
	sun = m_sceneManager->addSphereSceneNode(PLANET_RADIUS / 3, 36, parent, -1);
	if (m_sunTexture)
		sun->setMaterialTexture(0, m_sunTexture);
	sun->setMaterialFlag(video::EMF_LIGHTING, false);

	m_sceneManager->setAmbientLight(video::SColorf(0.3f, 0.3f, 0.3f, 0.0f));
	light = m_sceneManager->addLightSceneNode(parent,
						  core::vector3df(0.0f, 0.0f, 0.0f),
						  video::SColorf(0.4f, 0.4f, 0.6f, 0.0f), 50000.0f);
	light->getLightData().AmbientColor = video::SColorf(0.01, 0.01, 0.01, 0.01);
	light->getLightData().DiffuseColor = video::SColorf(0.5, 0.5, 0.5, 0.2);
	light->getLightData().SpecularColor = video::SColorf(0.7, 0.7, 0.7, 0.7);

	light->setPosition(core::vector3df(0.0f, 5000.0f, 0.0f));
	sun->setPosition(core::vector3df(0.0f, 500, 0.0f));
	parent->setRotation(core::vector3df(30.0f, 30.0f, 0.0f));
	animator = m_sceneManager->createRotationAnimator(core::vector3df(-0.15f, 0.0f, -0.05f));
	parent->addAnimator(animator);
	animator->drop();
	return (true);
}

void	Engine::loop(VisuComm *visuComm)
{
	while (m_device->run())
	{
		m_driver->beginScene (true, true,
							  video::SColor(255, 0, 0, 0));
		visuComm->launchOnce();
		m_mapData->AnimParticleEmitters(m_device->getTimer()->getTime());
		m_mapData->checkAnimationsEnd();
		m_mapData->hideItemsOnInoccupiedSquares();
		m_sceneManager->drawAll();
		m_gui->drawAll();
		m_driver->endScene();
	}
}
