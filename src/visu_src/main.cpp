// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2014/05/28 11:59:19 by glourdel          #+#    #+#             //
//   Updated: 2014/05/31 11:46:11 by glourdel         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <irrlicht.h>

using namespace std;
using namespace irr;

int			main(void)
{
	cout << "visu here !" << endl;
	IrrlichtDevice *device = createDevice (
		video::EDT_OPENGL,
		core::dimension2d<u32>(800,600),
		32,
		false,
		true,
		false,
		0);
	video::IVideoDriver* driver = device->getVideoDriver();
	scene::ISceneManager *sceneManager = device->getSceneManager();
	scene::IMeshSceneNode	*cube;
	cube = sceneManager->addCubeSceneNode(10.0f, 0, -1,
										  core::vector3df(0.0f, 0.0f, 20.0f));
	cube->setMaterialFlag(video::EMF_WIREFRAME, true);
    /* CAMERA */
    
	irr::SKeyMap keyMap[5];                    // re-assigne les commandes
    keyMap[0].Action = irr::EKA_MOVE_FORWARD;  // avancer
    keyMap[0].KeyCode = irr::KEY_KEY_W;        // w
    keyMap[1].Action = irr::EKA_MOVE_BACKWARD; // reculer
    keyMap[1].KeyCode = irr::KEY_KEY_S;        // s
    keyMap[2].Action = irr::EKA_STRAFE_LEFT;   // a gauche
    keyMap[2].KeyCode = irr::KEY_KEY_A;        // a
    keyMap[3].Action = irr::EKA_STRAFE_RIGHT;  // a droite
    keyMap[3].KeyCode = irr::KEY_KEY_D;        // d
    keyMap[4].Action = irr::EKA_JUMP_UP;       // saut
    keyMap[4].KeyCode = irr::KEY_SPACE;        // barre espace

    sceneManager->addCameraSceneNodeFPS(       // ajout de la camera FPS
        0,                                     // pas de noeud parent
        100.0f,                                // vitesse de rotation
        0.1f,                                  // vitesse de deplacement
        -1,                                    // pas de numero d'ID
        keyMap,                                // on change la keymap
        5);   
	while(device->run())
	{
		driver->beginScene (true, true,
							video::SColor(255, 255, 255, 255));
		sceneManager->drawAll();
		driver->endScene();
	}
//	device->drop();  ==> fait segfaulter !
	return (0);
}
