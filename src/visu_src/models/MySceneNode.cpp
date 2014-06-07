// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   MySceneNode.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2014/06/05 18:16:21 by glourdel          #+#    #+#             //
//   Updated: 2014/06/07 22:19:22 by glourdel         ###   ########.fr       //
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
	const s32 orientation, const char *team)
{
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
//	m_son->setMaterialFlag(video::EMF_ANTI_ALIASING, true);
//	m_son->setMaterialFlag(video::EMF_ANISOTROPIC_FILTER, true);
	if (m_type == TRANTOR)
		m_son->setMaterialType(video::EMT_TRANSPARENT_ALPHA_CHANNEL_REF);
	else if (m_type == STONE)
	{
		m_son->getMaterial(0).Shininess = 100.0f;
		m_son->getMaterial(0).EmissiveColor = irr::video::SColor(255,0,255,255);
	}
	placeOn(m_boardPos.X, m_boardPos.Y, m_offset.X, m_offset.Y);
	if (m_type == TRANTOR)
		m_mapData->registerTrantor(this, m_boardPos.X, m_boardPos.Y, team);
	return (m_son);
}

bool						scene::MySceneNode::uninitialized()
{
	if (m_type == 0)
	{
		cout << "MySceneNode:: ERROR --> node was not initialized with init()" << endl;
		return (true);
	}
	return (false);
}

void						scene::MySceneNode::updateOrientation(const s32 newOrientation)
{
	f32		rotY;

	if (uninitialized())
		return ;
	m_orientation = newOrientation;
	switch (m_orientation)
	{
	case NORTH:
		rotY = 180.0f;
		break ;
	case EAST:
		rotY = -90.0f;
		break ;
	case WEST:
		rotY = 90.0f;
		break ;
	default:
		rotY = 0.0f;
		break ;
	}
	m_son->setRotation(core::vector3df(0.0f, rotY, 0.0f));
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
	const core::vector2df &offset)
{
	m_offset.X = offset.X;
	m_offset.Y = offset.Y;
}

core::vector2d<f32>			&scene::MySceneNode::getOffset(void) {
	return (m_offset);
}

s32							scene::MySceneNode::getType(void) {
	return (m_type);
}

void						scene::MySceneNode::setBoardPos(
	const core::vector2di &newPos)
{
	m_boardPos = newPos;
}

core::vector2di				scene::MySceneNode::getBoardPos(void) {
	return (m_boardPos);
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
		moveTo(core::vector3df(180.0f, 0.0f, 0.0f), 0.8f, 0, 0, 2);
		break ;
	case 2:
		m_diveBuf.state = 3;
		moveToSquare(m_diveBuf.to.X, m_diveBuf.to.Y, 0.5f, 0.9f, 0.8f, 87, 106, 3);
		break ;
		// End state of both dives :
	case 3:
		m_diveBuf.state = -1;
		// moveTo uniquement pour declancher le prochain diveContinue :
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
		// moveTo uniquement pour declancher le prochain diveContinue :
		moveTo(core::vector3df(0.0f, 0.0f, 0.0f), 0.8f, 0, 0, 6);
		break ;
	case 6:
		m_diveBuf.state = 3;
		moveToSquare(m_diveBuf.to.X, m_diveBuf.to.Y, 0.5f, 0.0f, 0.8f, 87, 106, 3);
		break ;
	}
}
