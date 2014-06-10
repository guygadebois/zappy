// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   MapData_animations.cpp                             :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2014/06/10 16:29:24 by glourdel          #+#    #+#             //
//   Updated: 2014/06/10 16:29:46 by glourdel         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include "MapData.h"
#include "MySceneNode.h"

using namespace std;

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
