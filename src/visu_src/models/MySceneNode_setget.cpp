// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   MySceneNode_setget.cpp                             :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2014/06/09 11:57:24 by glourdel          #+#    #+#             //
//   Updated: 2014/06/19 15:28:58 by glourdel         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "MySceneNode.h"

u8							scene::MySceneNode::getOrientation(void) const
{
	return (m_orientation);
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
		rotY = 90.0f;
		break ;
	case WEST:
		rotY = -90.0f;
		break ;
	default:
		rotY = 0.0f;
		break ;
	}
	m_son->setRotation(core::vector3df(0.0f, rotY, 0.0f));
}

u32							scene::MySceneNode::getTeamNbr(void) const
{
	return (m_teamNbr);
}

void						scene::MySceneNode::setTeamNbr(u32 teamNbr)
{
	m_teamNbr = teamNbr;
}

core::vector2d<f32>			&scene::MySceneNode::getOffset(void)
{
	return (m_offset);
}

void						scene::MySceneNode::setOffset(
	const core::vector2df &offset)
{
	m_offset.X = offset.X;
	m_offset.Y = offset.Y;
}

s32							scene::MySceneNode::getMySceneType(void) const
{
	return (m_type);
}

core::vector2di				&scene::MySceneNode::getBoardPos(void)
{
	return (m_boardPos);
}

void						scene::MySceneNode::setBoardPos(
	const core::vector2di &newPos)
{
	m_boardPos = newPos;
}

void						scene::MySceneNode::setTexture(video::ITexture *texture)
{
	m_son->setMaterialTexture(0, texture);
	m_trantorTexture = texture;
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

u32							scene::MySceneNode::getId(void) const
{
	return (m_id);
}

u8							scene::MySceneNode::getLevel(void) const
{
	return (m_level);
}

bool						scene::MySceneNode::updateLevel(u8 level)
{
	f32		scale;

	m_level = level;
	scale = 0.8f + (level - 1) * 0.1f;
	m_son->setScale(core::vector3df(scale, scale, scale));
	return (true);
}

scene::IAnimatedMeshSceneNode	*scene::MySceneNode::getSon(void) const
{
	return (m_son);
}

string						scene::MySceneNode::getTeam(void) const
{
	return (m_team);
}
