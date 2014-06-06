// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   MySceneNode.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2014/06/05 18:16:21 by glourdel          #+#    #+#             //
//   Updated: 2014/06/06 12:12:28 by glourdel         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include "MySceneNode.h"

using namespace std;

scene::MySceneNode::MySceneNode(scene::ISceneNode* parent,
								scene::ISceneManager* mgr,
								MapData *mapData, s32 id)
	: scene::ISceneNode(parent, mgr, id), m_mapData(mapData)
{
	m_offset.X = 0;
	m_offset.Y = 0;
	m_box = core::aabbox3d<f32>(-20.0f, -20.0f, -20.0f, 20.0f, 20.0f, 20.0f);
}

scene::ISceneNode			*scene::MySceneNode::clone(
	scene::ISceneNode *newParent, scene::ISceneManager *newManager)
{
	if (!newParent)
		newParent = Parent;
	if (!newManager)
		newManager = SceneManager;
	scene::MySceneNode* clone;
	clone = new scene::MySceneNode(newParent, newManager, m_mapData, ID);
	clone->setOffset(m_offset);
	clone->cloneMembers(this, newManager);
	clone->drop();
	return (clone);
}

void						scene::MySceneNode::OnRegisterSceneNode()
{
	if (IsVisible)
		SceneManager->registerNodeForRendering(this, scene::ESNRP_SOLID);
	ISceneNode::OnRegisterSceneNode();
}

void						scene::MySceneNode::render()
{
	video::IVideoDriver* driver = SceneManager->getVideoDriver();

	driver->setMaterial(m_material);
	driver->setTransform(video::ETS_WORLD, AbsoluteTransformation);
	driver->draw3DBox(m_box, video::SColor(255, 255, 255, 255));
}

const core::aabbox3d<f32>	&scene::MySceneNode::getBoundingBox() const
{
	return (m_box);
}

u32							scene::MySceneNode::getMaterialCount() const
{
	return (1);
}

video::SMaterial			&scene::MySceneNode::getMaterial(u32 i)
{
	return (m_material);
}

// My methods :
void						scene::MySceneNode::setOffset(
	const core::vector2d<f32> &offset)
{
	m_offset.X = offset.X;
	m_offset.Y = offset.Y;
}

core::vector2d<f32>			&scene::MySceneNode::getOffset(void)
{
	return (m_offset);
}

void						scene::MySceneNode::rotate(
	const core::vector3df &rotation)
{
	setRotation(getRotation() + rotation);
}

void						scene::MySceneNode::placeOn(const u32 X, const u32 Y,
														const f32 offsetX, const f32 offsetY)
{
	core::vector3df		rotation;

	if (offsetX < -0.00000000001f || offsetX > 1.0f)
	{
		cout << "scene::MySceneNode::placeOn(): INVALID ARGUMENT -> offsetX must be between 0 and 1. Given: " << offsetX << endl;
		return ;
	}
	if (offsetY < -0.00000000001f || offsetY > 1.0f)
	{
		cout << "scene::MySceneNode::placeOn(): INVALID ARGUMENT -> offsetY must be between 0 and 1. Given: " << offsetY << endl;
		return ;
	}
	rotation.X = 45.0f + 90.0f / m_mapData->getGridSize().Height * Y;
	rotation.Y = 360.0f / m_mapData->getGridSize().Width * X;
	rotation.Z = 0.0f;
	// add offset to move somewhere on the square
	rotation.X += 90.0f / m_mapData->getGridSize().Height * offsetY;
	rotation.Y += 360.0f / m_mapData->getGridSize().Width * offsetX;
	setOffset(core::vector2d<f32>(offsetX, offsetY));
	setRotation(rotation);
}

void						scene::MySceneNode::moveTo(
	const u32 X, const u32 Y, const f32 offsetX, const f32 offsetY)
{
	// scene::ISceneNodeAnimator*		animX;
	// scene::ISceneNodeAnimator*		animY;

	// animX = SceneManager->createRotationAnimator(core::vector3df(0.1f * rotation.X / rotation.Y, 0.0f, 0.0f));
	// animY = SceneManager->createRotationAnimator(core::vector3df(0.1f * rotation.Y / rotation.X, 0.0f, 0.0f));
	// if (animX && animY)
	// {
	// 	addAnimator(animX);
	// 	addAnimator(animY);
	// 	animX->drop();
	// 	animY->drop();
	// }
}

