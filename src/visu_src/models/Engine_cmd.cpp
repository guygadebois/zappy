// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Engine_cmd.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2014/06/11 11:38:27 by glourdel          #+#    #+#             //
//   Updated: 2014/06/11 13:57:57 by glourdel         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <stdlib.h>
#include "Engine.h"
#include "MySceneNode.h"
#include "mystring.h"
#include "errors.h"

using namespace std;

bool	Engine::setSquareContent(const string line)
{
	vector<string>	*tokens;
	u32				x;
	u32				y;
	bool			ret;

	ret = true;
	tokens = mystring::strsplit(line);
	if (tokens->size() != 10)
	{
		cout << "Engine::setSquareContent ERROR --> invalid line format" << endl;
		return (false);
	}
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
	// repondre "bct X Y\n"
//	if (m_mapData->knowAllSquares())
		// repondre "mct\n"
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
	{
		cout << "Engine::updateTrantorPosition ERROR --> invalid line format" << endl;
		return (false);
	}
	if ((trantor = m_mapData->getTrantorById(stoi((*tokens)[1]))) == NULL)
		return (false);
	x = stoi((*tokens)[2]);
	y = stoi((*tokens)[3]);
	orientation = stoi((*tokens)[4]);
	if (trantor->getOrientation() != orientation)
		trantor->updateOrientation(orientation);
	actualPos = trantor->getBoardPos();
	if (actualPos.X != x || actualPos.Y != y)
		trantor->moveToSquare(x, y);
//	repondre "ppo #n\n"
	return (true);
}
