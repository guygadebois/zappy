// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   MapData.cpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2014/06/03 15:25:43 by glourdel          #+#    #+#             //
//   Updated: 2014/06/07 15:31:13 by glourdel         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include "MapData.h"
#include "MySceneNode.h"

using namespace std;

MapData::MapData(u32 width, u32 height, u32 textWidth, u32 textHeight) : m_texturePSize(textWidth, textHeight), m_gridSize(width, height), m_matrix(width, vector<t_mapElem>(height))
{
	m_gridElemPSize.Width = m_texturePSize.Width / width;
	m_gridElemPSize.Height = m_texturePSize.Height / height / 2;
// Init matrix
	for (int i = 0; i < m_gridSize.Width; i++)
	{
		for (int j = 0; j < m_gridSize.Height; j++)
		{
			; // ajouter ce qu'on voudra
		}
	}
}

core::dimension2d<u32>	MapData::getGridSize()
{
	return (m_gridSize);
}

core::dimension2d<u32>	MapData::getTexturePSize()
{
	return (m_texturePSize);
}

core::dimension2d<u32>	MapData::getGridElemPSize()
{
	return (m_gridElemPSize);
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

void					MapData::registerTrantor(scene::MySceneNode *parentNode, u32 posX, u32 posY)
{
	m_trantors.push_back(parentNode);
	m_matrix[posX][posY].trantors.push_back(parentNode);
}

void					MapData::updatePosition(scene::MySceneNode *parentNode,
												const core::vector2di &newPos)
{
	core::vector2di		oldPos;

	oldPos = parentNode->getBoardPos();
	switch (parentNode->getType())
	{
	case TRANTOR:
		m_matrix[oldPos.X][oldPos.Y].trantors.remove(parentNode);
		m_matrix[newPos.X][newPos.Y].trantors.push_back(parentNode);
		parentNode->setBoardPos(newPos);
		break ;
	}
}
