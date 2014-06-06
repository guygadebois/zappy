// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   MapData.cpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2014/06/03 15:25:43 by glourdel          #+#    #+#             //
//   Updated: 2014/06/06 16:53:47 by glourdel         ###   ########.fr       //
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

void					MapData::registerAnimation(scene::ISceneNode *parentNode,
												   scene::ISceneNodeAnimator *anim,
												   const core::vector3df &oldRotation,
												   const core::vector2df &oldOffset,
												   const core::vector3df &Rotation,
												   const core::vector2df &newOffset)
{
	t_animation	*animation;

	animation = new t_animation;
	if (animation)
	{
		animation->parentNode = parentNode;
		animation->anim = anim;
		animation->fromRotation = oldRotation;
		animation->fromOffset = oldOffset;
		animation->Rotation = Rotation;
		animation->toOffset = newOffset;
		m_animations.push_back(animation);
	}
}

void					MapData::checkAnimationsEnd(void)
{
	list<t_animation *>::iterator	it;
	scene::MySceneNode				*parentNode;
	scene::IAnimatedMeshSceneNode	*meshNode;

	it = m_animations.begin();
	while (it != m_animations.end())
	{
		parentNode = static_cast<scene::MySceneNode *>((*it)->parentNode);
		if (parentNode->getRotation().X >= (*it)->fromRotation.X + (*it)->Rotation.X
			|| parentNode->getRotation().Y >= (*it)->fromRotation.Y + (*it)->Rotation.Y)
		{
			// Stop and delete anim :
			parentNode->removeAnimator((*it)->anim);
			delete (*it);
			m_animations.erase(it);
			// Stop running :
			meshNode = static_cast<scene::IAnimatedMeshSceneNode *>(*parentNode->getChildren().begin());
			meshNode->setFrameLoop(0, 39);
		}
		++it;
	}
}
