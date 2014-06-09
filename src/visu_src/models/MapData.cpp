// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   MapData.cpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2014/06/03 15:25:43 by glourdel          #+#    #+#             //
//   Updated: 2014/06/09 21:38:35 by glourdel         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <algorithm>
#include "MapData.h"
#include "MySceneNode.h"
#include "mystring.h"

using namespace std;

MapData::MapData(u32 width, u32 height, u32 textWidth, u32 textHeight)
	: m_matrix(width, vector<t_mapElem>(height)), m_gridSize(width, height),
	  m_texturePSize(textWidth, textHeight), m_timeUnit(-1)
{
	m_gridElemPSize.Width = m_texturePSize.Width / width;
	m_gridElemPSize.Height = m_texturePSize.Height / height / 2;
// Init matrix
	for (u32 i = 0; i < m_gridSize.Width; i++)
	{
		for (u32 j = 0; j < m_gridSize.Height; j++)
			m_matrix[i][j].init = false;
	}
}

void					MapData::registerAnimation(scene::MySceneNode *parentNode,
												   scene::ISceneNodeAnimator *anim,
												   const core::vector3df &oldRotation,
												   const core::vector3df &rotation,
												   int diveState)
{
	t_animation	*animation;

	animation = new t_animation;
	if (animation)
	{
		animation->parentNode = parentNode;
		animation->anim = anim;
		animation->fromRotation = oldRotation;
		animation->rotation = rotation;
		animation->diveState = diveState;
		m_animations.push_back(animation);
	}
}

bool					MapData::rotationAtEnd(const core::vector3df &rotation,
											   const core::vector3df &actualRotation,
											   const core::vector3df &fromRotation)
{
	bool	xTrue;
	bool	yTrue;

	xTrue = false;
	yTrue = false;
	if (rotation.X >= 0.0000001f)
	{
		if (actualRotation.X >= fromRotation.X + rotation.X)
			xTrue = true;
	}
	else if (actualRotation.X <= fromRotation.X + rotation.X)
		xTrue = true;
	if (rotation.Y >= 0.0000001f)
	{
		if (actualRotation.Y >= fromRotation.Y + rotation.Y)
			yTrue = true;
	}
	else if (actualRotation.Y <= fromRotation.Y + rotation.Y)
		yTrue = true;
	return (xTrue && yTrue);
}

void					MapData::checkAnimationsEnd(void)
{
	list<t_animation *>::iterator	it;
	scene::MySceneNode				*parentNode;
	scene::IAnimatedMeshSceneNode	*meshNode;

	it = m_animations.begin();
	while (it != m_animations.end())
	{
		parentNode = (*it)->parentNode;
		if (rotationAtEnd((*it)->rotation, parentNode->getRotation(), (*it)->fromRotation))
		{
			// If stops too late : replace on destination :
			parentNode->setRotation((*it)->fromRotation + (*it)->rotation);
			// Stop and delete anim :
			if ((*it)->diveState != -1)
				parentNode->diveContinue();
			parentNode->removeAnimator((*it)->anim);
			delete (*it);
			it = m_animations.erase(it);
			// Stop running :
			meshNode = static_cast<scene::IAnimatedMeshSceneNode *>(*parentNode->getChildren().begin());
			meshNode->setFrameLoop(0, 39);
			if ((*it)->diveState != -1)
				parentNode->diveContinue();
		}
		else
			++it;
	}
}

void					MapData::registerTrantor(scene::MySceneNode *parentNode, u32 posX, u32 posY, const char *team)
{
	string	tmp(team);
	u32		count;

	count = 0;
	m_trantors.push_back(parentNode);
	m_matrix[posX][posY].trantors.push_back(parentNode);
	for (list<string>::iterator it = m_teams.begin(); it != m_teams.end(); ++it, ++count)
	{
		if (*it == tmp)
		{
			parentNode->setTeamNbr(count);
			return ;
		}
	}
	parentNode->setTeamNbr(count);
	m_teams.push_back(tmp);
}

void					MapData::updatePosition(scene::MySceneNode *parentNode,
												const core::vector2di &newPos)
{
	core::vector2di		oldPos;

	oldPos = parentNode->getBoardPos();
	switch (parentNode->getMySceneType())
	{
	case TRANTOR:
		m_matrix[oldPos.X][oldPos.Y].trantors.remove(parentNode);
		m_matrix[newPos.X][newPos.Y].trantors.push_back(parentNode);
		parentNode->setBoardPos(newPos);
		break ;
	//
		// continuer pour les autres types...
	//
	}
}

bool					MapData::isReady(void) const
{
	if (m_timeUnit <= 0)
		return (false);
	for (u32 i = 0; i < m_gridSize.Width; i++)
	{
		for (u32 j = 0; j < m_gridSize.Height; j++)
		{
			if (m_matrix[i][j].init == false)
				return (false);
		}
	}
	return (true);
}

void					MapData::updateSquareContent(const string line)
{
	vector<string>	*tokens;
	u32				x;
	u32				y;

	tokens = mystring::strsplit(line);
	if (tokens->size() != 10)
	{
		cout << "MapData::updateSquareContent ERROR --> invalid line format" << endl;
		return ;
	}
	x = stoi((*tokens)[1]);
	y = stoi((*tokens)[2]);
	m_matrix[x][y].init = true;
	addItemToList(&m_matrix[x][y].item[0], stoi((*tokens)[3]));
	addItemToList(&m_matrix[x][y].item[1], stoi((*tokens)[4]));
	addItemToList(&m_matrix[x][y].item[2], stoi((*tokens)[5]));
	addItemToList(&m_matrix[x][y].item[3], stoi((*tokens)[6]));
	addItemToList(&m_matrix[x][y].item[4], stoi((*tokens)[7]));
	addItemToList(&m_matrix[x][y].item[5], stoi((*tokens)[8]));
	addItemToList(&m_matrix[x][y].item[6], stoi((*tokens)[9]));
	delete (tokens);
}

void					MapData::addItemToList(list<scene::MySceneNode *> *destList, u32 nbr)
{
	for (u32 i = 0; i < nbr; ++i)
	{
		//continuer ici...
	}
}
