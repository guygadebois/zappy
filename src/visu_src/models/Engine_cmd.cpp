// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Engine_cmd.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2014/06/11 11:38:27 by glourdel          #+#    #+#             //
//   Updated: 2014/06/24 12:41:31 by glourdel         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <stdlib.h>
#include "Engine.h"
#include "MySceneNode.h"
#include "mystring.h"
#include "errors.h"

using namespace std;

bool	Engine::treatCmd(const string line)
{
	string	cmd = line.substr(0, 3);

	if (cmd == "sgt")
		return (setTimeUnit(line));
	if (cmd == "bct")
		return (setSquareContent(line));
	if (cmd == "pnw")
		return (newClientConnected(line));
	if (cmd == "ppo")
		return (updateTrantorPosition(line));
	if (cmd == "plv")
		return (updateTrantorLevel(line));
	if (cmd == "pgt")
		return (takeRessource(line));
	if (cmd == "pdr")
		return (dropRessource(line));
	if (cmd == "pex")
		return (expulse(line));
	if (cmd == "pbc")
		return (broadcast(line));
	if (cmd == "pdi" || cmd == "edi")
		return (die(line));
	if (cmd == "pic")
		return (startIncantation(line));
	if (cmd == "pie")
		return (endIncantation(line));
	if (cmd == "pfk")
		return (deliverEgg(line));
	if (cmd == "enw")
		return (eggDelivered(line));
	if (cmd == "eht")
		return (eggHatchOut(line));
	if (cmd == "seg")
		return (endOfGame(line));
	cout << "WARNING -> Commande inconnue : " << line << endl;
	return (false);
}

bool	Engine::setTimeUnit(const string line)
{
	vector<string>	*tokens;
	s32				timeUnit;

	tokens = mystring::strsplit(line);
	if (tokens->size() != 2)
		return (err_msg("Engine::setTimeUnit ERROR --> invalid line format"));
	timeUnit = stoi((*tokens)[1]);
	if (timeUnit <= 0)
		return (err_msg("Engine::setTimeUnit ERROR --> time unit must be greater than 0"));
	m_mapData->setTimeUnit(timeUnit);
	if (timeUnit <= VISU_MIN_TIMEUNIT)
		;
// repondre "sst 100\n" au serveur
	delete (tokens);
	return (true);
}

bool	Engine::setSquareContent(const string line)
{
	vector<string>	*tokens;
	u32				x;
	u32				y;
	bool			ret;

	if (m_started)
		return (true);
	ret = true;
	tokens = mystring::strsplit(line);
	if (tokens->size() != 10)
		return (err_msg("Engine::setSquareContent ERROR --> invalid line format"));
	x = stoi((*tokens)[1]);
	y = stoi((*tokens)[2]);
	m_mapData->setMatrixSquareInit(x, y, true);
	ret = ret && addItem(0, stoi((*tokens)[3]), x, y);
	ret = ret && addItem(1, stoi((*tokens)[4]), x, y);
	ret = ret && addItem(2, stoi((*tokens)[5]), x, y);
	ret = ret && addItem(3, stoi((*tokens)[6]), x, y);
	ret = ret && addItem(4, stoi((*tokens)[7]), x, y);
	ret = ret && addItem(5, stoi((*tokens)[8]), x, y);
	ret = ret && addItem(6, stoi((*tokens)[9]), x, y);
	delete (tokens);
	return (ret);
}

bool	Engine::addItem(const u8 itemNbr, const u32 howMany, const u32 x, const u32 y)
{
	scene::MySceneNode				*parent;
	scene::IAnimatedMeshSceneNode	*son;

	for (u32 i = 0; i < howMany; ++i)
	{
		if (m_itemMesh[itemNbr] == NULL || (parent = m_emptyParent->clone()) == NULL)
			return (err_msg("Engine::addItem ERROR -> m_emptyParent->clone() failed..."));
		if (!(son = parent->init(m_itemMesh[itemNbr], itemNbr ? GEM : FOOD)))
			return (err_msg("Engine::addItem ERROR -> parent->init() failed..."));
		parent->placeOnSquare(x, y, (float)rand() / RAND_MAX, (float)rand() / RAND_MAX);
		if (itemNbr == 0)
			son->setMaterialTexture(0, m_gemTexture[5]);
		else
			son->setMaterialTexture(0, m_gemTexture[itemNbr - 1]);
		m_mapData->registerItem(parent, x, y, itemNbr);
	}
	return (true);
}

bool	Engine::updateTrantorPosition(const string line)
{
	scene::MySceneNode	*trantor;
	vector<string>		*tokens;
	core::vector2di		actualPos;
	s32					x;
	s32					y;
	u32					orientation;

	tokens = mystring::strsplit(line);
	if (tokens->size() != 5)
		return (err_msg("Engine::updateTrantorPosition ERROR --> invalid line format"));
	if ((trantor = m_mapData->getTrantorById(stoi((*tokens)[1]))) == NULL)
		return (false);
	x = stoi((*tokens)[2]);
	y = stoi((*tokens)[3]);
	orientation = stoi((*tokens)[4]);
	if (trantor->getOrientation() != orientation)
		trantor->updateOrientation(orientation);
	actualPos = trantor->getBoardPos();
	m_mapData->updatePosition(trantor, core::vector2di(x, y));
	if (actualPos.X != x || actualPos.Y != y)
	{
		if (actualPos.Y == 0 && y == (s32)m_mapData->getGridSize().Height - 1)
			trantor->diveUpTo(x, y);
		else if (actualPos.Y == (s32)m_mapData->getGridSize().Height - 1 && y == 0)
			trantor->diveDownTo(x, y);
		else
			trantor->moveToSquare(x, y);
	}
	delete (tokens);
	return (true);
}

bool	Engine::newClientConnected(const string line)
{
	vector<string>		*tokens;
	bool				ret;
	u32					id;

	tokens = mystring::strsplit(line);
	if (tokens->size() != 7)
	{
		return (err_msg("Engine::newClientConnected ERROR --> invalid line format"));
	}
	id = stoi((*tokens)[1]);
	if (m_mapData->getTrantorById(id, false) != NULL)
		return (err_msg("Engine::newClientConnected ERROR -> client alwready exists whit the same id"));
	ret = addTrantor(id, stoi((*tokens)[2]), stoi((*tokens)[3]),
					 stoi((*tokens)[4]), stoi((*tokens)[5]), (*tokens)[6]);
	ret = true;
	delete (tokens);
	return (ret);
}

bool	Engine::updateTrantorLevel(const string line)
{
	scene::MySceneNode	*trantor;
	vector<string>		*tokens;
	u32					id;
	bool				ret;

	tokens = mystring::strsplit(line);
	if (tokens->size() != 3)
		return (err_msg("Engine::updateTrantorLevel ERROR --> invalid line format"));
	id = stoi((*tokens)[1]);
	if ((trantor = m_mapData->getTrantorById(id)) == NULL)
		return (false);
	ret = trantor->updateLevel(stoi((*tokens)[2]));
	delete (tokens);
	return (ret);
}

bool	Engine::takeRessource(const string line)
{
	scene::MySceneNode	*trantor;
	vector<string>		*tokens;
	u32					id;
	bool				ret;

	tokens = mystring::strsplit(line);
	if (tokens->size() != 3)
		return (err_msg("Engine::takeRessource ERROR --> invalid line format"));
	id = stoi((*tokens)[1]);
	if ((trantor = m_mapData->getTrantorById(id)) == NULL)
		return (false);
	ret = trantor->pickRessource(stoi((*tokens)[2]));
	delete (tokens);
	return (ret);
}

bool	Engine::dropRessource(const string line)
{
	scene::MySceneNode	*trantor;
	vector<string>		*tokens;
	u32					id;
	bool				ret;

	tokens = mystring::strsplit(line);
	if (tokens->size() != 3)
		return (err_msg("Engine::dropRessource ERROR --> invalid line format"));
	id = stoi((*tokens)[1]);
	if ((trantor = m_mapData->getTrantorById(id)) == NULL)
		return (false);
	ret = trantor->dropRessource(stoi((*tokens)[2]));
	delete (tokens);
	return (ret);
}

bool	Engine::expulse(const string line)
{
	list<scene::MySceneNode *>				*trantorList;
	list<scene::MySceneNode *>::iterator	it;
	scene::MySceneNode						*trantor;
	vector<string>							*tokens;
	u32										id;
	bool									ret;

	tokens = mystring::strsplit(line);
	if (tokens->size() != 2)
		return (err_msg("Engine::expulse ERROR --> invalid line format"));
	id = stoi((*tokens)[1]);
	if ((trantor = m_mapData->getTrantorById(id)) == NULL)
		return (false);
	ret = trantor->expulse();
	if ((trantorList = m_mapData->getTrantorsByPos(trantor->getBoardPos())))
	{
		while (trantorList->size() > 1)
		{
			for (it = trantorList->begin(); it != trantorList->end(); ++it)
			{
				if (*it != trantor)
				{
					(*it)->isExpulsed(trantor->getOrientation());
					break ;
				}
			}
		}
	}
	delete (tokens);
	return (ret);
}

bool	Engine::broadcast(const string line)
{
	scene::MySceneNode				*trantor;
	vector<string>					*tokens;
	u32								id;
	bool							ret;

	tokens = mystring::strsplit(line);
	if (tokens->size() != 3)
		return (err_msg("Engine::takeRessource ERROR --> invalid line format"));
	id = stoi((*tokens)[1]);
	if ((trantor = m_mapData->getTrantorById(id)) == NULL)
		return (false);
	launchBroadcastParticles(trantor);
	ret = trantor->broadcast((*tokens)[2]);
	delete (tokens);
	return (ret);
}

bool	Engine::launchBroadcastParticles(scene::MySceneNode *trantor)
{
	scene::IParticleSystemSceneNode		*partSys;
	scene::IParticleRingEmitter			*emitter;
	scene::IParticleRotationAffector	*affector;
	PartEmitterAnim						*anim;

	partSys = m_sceneManager->addParticleSystemSceneNode(false);
	emitter = partSys->createRingEmitter(
		core::vector3df(0.0f, PLANET_RADIUS, 0.0f),
		10.0f,
		1.0f,
		core::vector3df(0.0f, 0.03f, 0.0f),
		5000, 10000,
		video::SColor(255, 0, 0, 0),
		video::SColor(255, 255, 255, 255),
		200,
		200,
		0,
		core::dimension2df(1.0f, 1.0f),
		core::dimension2df(2.0f, 2.0f)
		);
	partSys->setEmitter(emitter);
	emitter->drop();
	affector = partSys->createRotationAffector();
	partSys->addAffector(affector);
	affector->drop();
	partSys->setRotation(trantor->getRotation());
	if (m_particleTexture1)
		partSys->setMaterialTexture(0, m_particleTexture1);
	partSys->setMaterialType(irr::video::EMT_TRANSPARENT_ALPHA_CHANNEL);
	anim = new PartEmitterAnim(partSys, emitter,
							   m_device->getTimer()->getTime(), 10000);
	m_mapData->registerPartEmitterAnim(anim);
	return (true);
}

bool	Engine::die(const string line)
{
	scene::MySceneNode				*trantor;
	vector<string>					*tokens;
	u32								id;

	tokens = mystring::strsplit(line);
	if (tokens->size() != 2)
		return (err_msg("Engine::die ERROR --> invalid line format"));
	id = stoi((*tokens)[1]);
	if ((trantor = m_mapData->getTrantorById(id)) == NULL)
		return (false);
	trantor->die();
	delete (tokens);
	return (true);
}

bool	Engine::startIncantation(const string line)
{
	scene::MySceneNode				*trantor;
	vector<string>					*tokens;
	u32								x;
	u32								y;
	u8								tokensSize;

	tokens = mystring::strsplit(line);
	if ((tokensSize = tokens->size()) < 5)
		return (err_msg("Engine::startIncantation ERROR --> invalid line format"));
	x = stoi((*tokens)[1]);
	y = stoi((*tokens)[2]);
	for (u8 i = 4; i < tokensSize; i++)
	{
		if ((trantor = m_mapData->getTrantorById(stoi((*tokens)[i]))) == NULL)
			return (false);
		trantor->startIncantation();
	}
	startIncantationParticles(x, y);
	delete (tokens);
	return (true);
}

bool	Engine::startIncantationParticles(u32 posX, u32 posY)
{
	scene::IParticleSystemSceneNode		*partSys;
	scene::IParticleRingEmitter			*emitter;
	scene::IParticleAffector			*affector;
	core::vector3df						rotation;
	f32									radiusX;
	f32									radiusY;

	radiusX = 90.0f / m_mapData->getGridSize().Height;
	radiusY = 250.0f / m_mapData->getGridSize().Width;
	partSys = m_sceneManager->addParticleSystemSceneNode(false);
	emitter = partSys->createRingEmitter(
		core::vector3df(0.0f, PLANET_RADIUS, 0.0f),
		(radiusX > radiusY ? radiusX : radiusY),
		1.0f,
		core::vector3df(0.0f, 0.03f, 0.0f),
		1500, 2000,
		video::SColor(255, 0, 0, 0),
		video::SColor(255, 255, 255, 255),
		300,
		600,
		0,
		core::dimension2df(0.8f, 0.8f),
		core::dimension2df(0.4f, 0.4f)
		);
	partSys->setEmitter(emitter);
	emitter->drop();
	affector = partSys->createFadeOutParticleAffector(irr::video::SColor(0,0,0,0),
		100);
	partSys->addAffector(affector);
	affector->drop();
	rotation.X = 45.0f + 90.0f / m_mapData->getGridSize().Height * posY;
	rotation.Y = 360.0f / m_mapData->getGridSize().Width * posX;
	rotation.Z = 0.0f;
	// add offset :
	rotation.X += 90.0f / m_mapData->getGridSize().Height * 0.5f;
	rotation.Y += 360.0f / m_mapData->getGridSize().Width * 0.5f;
	partSys->setRotation(rotation);
	if (m_particleTexture2)
		partSys->setMaterialTexture(0, m_particleTexture2);
	partSys->setMaterialFlag(video::EMF_ZWRITE_ENABLE, false);
	partSys->setMaterialType(video::EMT_TRANSPARENT_ADD_COLOR);
	m_mapData->setMatrixPartSys(posX, posY, partSys);
	return (true);
}

bool	Engine::endIncantation(const string line)
{
	list<scene::MySceneNode *>		*trantors;
	vector<string>					*tokens;
	u32								x;
	u32								y;

	tokens = mystring::strsplit(line);
	if (tokens->size() != 4)
		return (err_msg("Engine::endIncantation ERROR --> invalid line format"));
	x = stoi((*tokens)[1]);
	y = stoi((*tokens)[2]);
	trantors = m_mapData->getTrantorsByPos(core::vector2di(x, y));
	for (list<scene::MySceneNode *>::iterator it = trantors->begin();
		 it != trantors->end(); it++)
	{
		(*it)->stopIncantation();
	}
	m_mapData->getMatrixPartSys(x, y)->setEmitter(NULL);
	delete (tokens);
	return (true);
}

bool	Engine::deliverEgg(const string line)
{
	scene::MySceneNode				*trantor;
	vector<string>					*tokens;

	tokens = mystring::strsplit(line);
	if (tokens->size() != 2)
		return (err_msg("Engine::deliverEgg ERROR --> invalid line format"));
	if ((trantor = m_mapData->getTrantorById(stoi((*tokens)[1]))) == NULL)
		return (false);
	trantor->deliverEgg();
	delete (tokens);
	return (true);
}

bool	Engine::eggDelivered(const string line)
{
	scene::MySceneNode				*trantor;
	vector<string>					*tokens;
	u32								x;
	u32								y;
	core::vector2df					offset;

	tokens = mystring::strsplit(line);
	if (tokens->size() != 5)
		return (err_msg("Engine::eggDeliver ERROR --> invalid line format"));
	x = stoi((*tokens)[3]);
	y = stoi((*tokens)[4]);
	if ((trantor = m_mapData->getTrantorById(stoi((*tokens)[2]))) == NULL)
		return (false);
	trantor->stopDeliveringEgg();
	offset = trantor->getOffset();
	addEgg(stoi((*tokens)[1]), x, y, offset.X, offset.Y, trantor->getTeam());
	delete (tokens);
	return (true);
}

bool	Engine::eggHatchOut(const string line)
{
	scene::MySceneNode				*egg;
	vector<string>					*tokens;

	tokens = mystring::strsplit(line);
	if (tokens->size() != 2)
		return (err_msg("Engine::eggHatchOut ERROR --> invalid line format"));
	if ((egg = m_mapData->getTrantorById(stoi((*tokens)[1]))) == NULL)
		return (false);
	egg->eggBecomeTrantor(m_trentorMesh);
	delete (tokens);
	return (true);
}

bool	Engine::endOfGame(const string line)
{
	vector<string>					*tokens;
	string							msg;
	wstring							w_msg;

	tokens = mystring::strsplit(line);
	if (tokens->size() != 2)
		return (err_msg("Engine::endOfGame ERROR --> invalid line format"));
	m_mapData->setEndOfGame((*tokens)[1]);
	msg = (*tokens)[1] + " won the game !";
	mystring::StringToWString(w_msg, msg);
	m_gui->addMessageBox(L"End of game", w_msg.c_str());
	delete (tokens);
	return (true);
}
