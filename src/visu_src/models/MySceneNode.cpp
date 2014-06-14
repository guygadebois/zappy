// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   MySceneNode.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2014/06/05 18:16:21 by glourdel          #+#    #+#             //
//   Updated: 2014/06/14 13:17:44 by glourdel         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <cmath>
#include "MySceneNode.h"

using namespace std;

scene::MySceneNode::MySceneNode(scene::ISceneNode* parent,
								scene::ISceneManager* mgr,
								MapData *mapData, s32 id)
	: scene::ISceneNode(parent, mgr, id), m_mapData(mapData)
{
	m_offset.X = 0;
	m_offset.Y = 0;
	m_diveBuf.state = -1;
	m_box = core::aabbox3d<f32>(-20.0f, -20.0f, -20.0f, 20.0f, 20.0f, 20.0f);
	m_type = 0; // 0 = uninitialized
	m_id = -1; // -1 = uninitialized
}

scene::MySceneNode			*scene::MySceneNode::clone(
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

scene::IAnimatedMeshSceneNode	*scene::MySceneNode::init(
	scene::IAnimatedMesh *mesh, s32 type,
	const core::vector2di &boardPos, const u32 itemId, const u32 level,
	const s32 orientation, const string team)
{
	f32			scale;

	m_boardPos = boardPos;
	m_level = level;
	m_team = team;
	setOffset(core::vector2df(0.5f, 0.5f));
	m_son = SceneManager->addAnimatedMeshSceneNode(mesh, this);
	if (m_son == NULL)
		return (NULL);
	m_id = itemId;
	m_type = type;
	updateOrientation(orientation);
	m_son->setPosition(core::vector3df(0, PLANET_RADIUS, 0));
	m_son->setAnimationSpeed(5);
	m_son->setFrameLoop(0, 39);
	m_son->setMaterialFlag(video::EMF_NORMALIZE_NORMALS, true);
//	m_son->setMaterialFlag(video::EMF_ANTI_ALIASING, true);
//	m_son->setMaterialFlag(video::EMF_ANISOTROPIC_FILTER, true);
	if (m_type == TRANTOR)
	{
		m_son->setMaterialType(video::EMT_TRANSPARENT_ALPHA_CHANNEL_REF);
		m_mapData->registerTrantor(this, m_boardPos.X, m_boardPos.Y, team);
		scale = 0.8f + (level - 1) * 0.1f;
		m_son->setScale(core::vector3df(scale, scale, scale));
	}
	else if (m_type == GEM)
	{
		m_son->getMaterial(0).Shininess = 20.0f;
//		m_son->getMaterial(0).EmissiveColor.set(90, 90, 90, 90);
//		m_son->getMaterial(0).AmbientColor.set(90, 90, 90, 90);
//		m_son->getMaterial(0).DiffuseColor.set(90, 90, 90, 90);
//		m_son->getMaterial(0).SpecularColor.set(255, 255, 255, 255);
		m_son->setScale(core::vector3df(0.5f, 0.5f, 0.5f));
	}
	else if (m_type == FOOD)
	{
//
	}
	placeOnSquare(m_boardPos.X, m_boardPos.Y, m_offset.X, m_offset.Y);
	return (m_son);
}

bool						scene::MySceneNode::uninitialized()
{
	if (m_type == 0)
	{
		cout << "MySceneNode:: ERROR --> node was not iniitalized with init()" << endl;
		return (true);
	}
	return (false);
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
}

void						scene::MySceneNode::rotate(
	const core::vector3df &rotation)
{
	setRotation(getRotation() + rotation);
}

void						scene::MySceneNode::placeOnSquare(
	const u32 X, const u32 Y, const f32 offsetX, const f32 offsetY)
{
	core::vector3df		rotation;

	if (offsetX < -0.00000000001f || offsetX > 1.0f)
	{
		cout << "scene::MySceneNode::placeOnSquare(): INVALID ARGUMENT -> offsetX must be between 0 and 1. Given: " << offsetX << endl;
		return ;
	}
	if (offsetY < -0.00000000001f || offsetY > 1.0f)
	{
		cout << "scene::MySceneNode::placeOnSquare(): INVALID ARGUMENT -> offsetY must be between 0 and 1. Given: " << offsetY << endl;
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

void						scene::MySceneNode::moveToSquare(
	const u32 X, const u32 Y, const f32 offsetX, const f32 offsetY,
	const f32 speed, const u32 frameStart, const u32 frameEnd, u32 diveState)
{
	core::vector3df					rotation;

	if (offsetX < -0.00000000001f || offsetX > 1.0f)
	{
		cout << "scene::MySceneNode::moveToSquare(): INVALID ARGUMENT -> offsetX must be between 0 and 1. Given: " << offsetX << endl;
		return ;
	}
	if (offsetY < -0.00000000001f || offsetY > 1.0f)
	{
		cout << "scene::MySceneNode::moveToSquare(): INVALID ARGUMENT -> offsetY must be between 0 and 1. Given: " << offsetY << endl;
		return ;
	}
	rotation.X = 45.0f + 90.0f / m_mapData->getGridSize().Height * Y;
	rotation.Y = 360.0f / m_mapData->getGridSize().Width * X;
	rotation.Z = 0.0f;
	// add offset to move somewhere on the square :
	rotation.X += 90.0f / m_mapData->getGridSize().Height * offsetY;
	rotation.Y += 360.0f / m_mapData->getGridSize().Width * offsetX;
	// relative to actual position :
	moveTo(rotation, speed, frameStart, frameEnd, diveState);
	setOffset(core::vector2d<f32>(offsetX, offsetY));
}

void						scene::MySceneNode::moveTo(
	const core::vector3df &constRotation,
	const f32 speed, const u32 frameStart, const u32 frameEnd, u32 diveState)
{
	core::vector3df					rotation = constRotation;
	scene::ISceneNodeAnimator*		anim;
	core::vector2df					animSpeed;
	scene::IAnimatedMeshSceneNode	*meshNode;

	if (uninitialized())
		return ;
	rotation -= getRotation();
	if (rotation.X + rotation.Y == 0)
		return ;

	if (rotation.Y > 180.0f)
		rotation.Y -= 360.0f;

	// animation :
	animSpeed.X = speed * rotation.X / (fabs(rotation.X) + fabs(rotation.Y));
	animSpeed.Y = speed * rotation.Y / (fabs(rotation.X) + fabs(rotation.Y));
	anim = SceneManager->createRotationAnimator(core::vector3df(animSpeed.X, animSpeed.Y, 0.0f));
	if (anim)
	{
		addAnimator(anim);
		anim->drop();
		m_mapData->registerAnimation(this, anim, getRotation(), rotation, diveState);
		meshNode = static_cast<scene::IAnimatedMeshSceneNode *>(*getChildren().begin());
		meshNode->setFrameLoop(frameStart, frameEnd);
	}
	else
		cout << "MySceneNode::moveTo: ERROR -> could not create animators" << endl;
}

void						scene::MySceneNode::diveUpTo(
	const u32 X, const u32 Y, const f32 offsetX, const f32 offsetY)
{
	if (uninitialized())
		return ;
	m_diveBuf.state = 0;
	m_diveBuf.to.X = X;
	m_diveBuf.to.Y = Y;
	m_diveBuf.offset.X = offsetX;
	m_diveBuf.offset.Y = offsetY;
	moveToSquare(X, 0, 0.5f, 0.0f, 0.1f, 40, 45, 0);
}

void						scene::MySceneNode::diveDownTo(
	const u32 X, const u32 Y, const f32 offsetX, const f32 offsetY)
{
	if (uninitialized())
		return ;
	m_diveBuf.state = 4;
	m_diveBuf.to.X = X;
	m_diveBuf.to.Y = Y;
	m_diveBuf.offset.X = offsetX;
	m_diveBuf.offset.Y = offsetY;
	moveToSquare(X, m_mapData->getGridSize().Height - 1, 0.5f, 0.9f, 0.1f, 40, 45, 4);
}

void						scene::MySceneNode::diveContinue()
{
	switch (m_diveBuf.state)
	{
		// Dive Up ==> states 0 to 2 :
	case 0:
		m_diveBuf.state = 1;
		moveTo(core::vector3df(0.0f, 0.0f, 0.0f), 0.8f, 87, 106, 1);
		break ;
	case 1:
		m_diveBuf.state = 2;
		setRotation(core::vector3df(180.0f, 0.0f, 0.0f));
	case 2:
		m_diveBuf.state = 3;
		moveToSquare(m_diveBuf.to.X, m_diveBuf.to.Y, 0.5f, 0.9f, 0.8f, 87, 106, 3);
		break ;
		// End state of both dives :
	case 3:
		m_diveBuf.state = -1;
		moveToSquare(m_diveBuf.to.X, m_diveBuf.to.Y, m_diveBuf.offset.X, m_diveBuf.offset.Y, 0.1f, 40, 45, -1);
		break ;
		// Dive Down ==> states 4 to 6 :
	case 4:
		m_diveBuf.state = 5;
		moveTo(core::vector3df(180.0f, 0.0f, 0.0f), 0.8f, 87, 106, 5);
		break ;
	case 5:
		m_diveBuf.state = 6;
		setRotation(core::vector3df(0.0f, 0.0f, 0.0f));
	case 6:
		m_diveBuf.state = 3;
		moveToSquare(m_diveBuf.to.X, m_diveBuf.to.Y, 0.5f, 0.0f, 0.8f, 87, 106, 3);
		break ;
	}
}

bool						scene::MySceneNode::pickRessource(const u8 itemNbr)
{
	scene::IAnimatedMeshSceneNode	*meshNode;
	scene::MySceneNode				*item;
	scene::ISceneNodeAnimator*		anim;
	core::vector3df					startPoint;
	core::vector3df					endPoint;

	if (uninitialized())
		return (false);
	meshNode = static_cast<scene::IAnimatedMeshSceneNode *>(*getChildren().begin());
	if ((item = m_mapData->pickItemFromList(itemNbr, getBoardPos())))
	{
		startPoint = item->m_son->getPosition();
		endPoint = startPoint + core::vector3df(0.0f, 10.0f, 0.0f);
		anim = SceneManager->createFlyStraightAnimator(startPoint, endPoint, 1500);
		if (anim)
		{
			item->m_son->addAnimator(anim);
			anim->drop();
		}
		m_mapData->registerFrameAnimation(this, 121, 128, 1, 39, 5, 1, true, item);
		meshNode->setFrameLoop(121, 219);
	}
	return (true);
}

bool						scene::MySceneNode::expulse(void)
{
	m_mapData->registerFrameAnimation(this, 46, 53, 1, 39, 5, 2);
	m_son->setFrameLoop(46, 219);
	m_son->setAnimationSpeed(10);
	return (true);
}

void						scene::MySceneNode::isExpulsed(const u8 orientation)
{
	s32						x;
	s32						y;
	core::dimension2d<s32>	board;
	core::vector2df			offset;

	offset = getOffset();
	board = m_mapData->getGridSize();
	x = m_boardPos.X;
	y = m_boardPos.Y;
	switch (orientation)
	{
	case 1:
		y = (y + board.Height - 1) % board.Height;
		break ;
	case 2:
		x = (x + 1) % board.Width;
		break ;
	case 3:
		y = (y + 1) % board.Height;
		break ;
	case 4:
		x = (x + board.Width - 1) % board.Width;
		break ;
	}
	if (m_boardPos.Y == 0 && y == board.Height - 1)
		diveUpTo(x, y, offset.X, offset.Y);
	else if (m_boardPos.Y == board.Height - 1 && y == 0)
		diveDownTo(x, y, offset.X, offset.Y);
	else
		moveToSquare(x, y, offset.X, offset.Y);
	m_mapData->updatePosition(this, core::vector2di(x, y));
}
