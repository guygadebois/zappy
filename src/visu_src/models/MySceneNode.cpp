// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   MySceneNode.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2014/06/05 18:16:21 by glourdel          #+#    #+#             //
//   Updated: 2014/06/05 19:05:14 by glourdel         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "MySceneNode.h"

irr::scene::MySceneNode::MySceneNode(irr::scene::ISceneNode* parent,
								irr::scene::ISceneManager* mgr, irr::s32 id)
: irr::scene::ISceneNode(parent, mgr, id)
{
	m_offset.X = 0;
	m_offset.Y = 0;
	m_box = irr::core::aabbox3d<irr::f32>(-20.0f, -20.0f, -20.0f, 20.0f, 20.0f, 20.0f);
}

irr::scene::ISceneNode				*irr::scene::MySceneNode::clone(
	irr::scene::ISceneNode *newParent, irr::scene::ISceneManager *newManager)
{
	if (!newParent)
		newParent = Parent;
	if (!newManager)
		newManager = SceneManager;
	irr::scene::MySceneNode* clone;
	clone = new irr::scene::MySceneNode(newParent, newManager, ID);
	clone->setOffset(m_offset);
	clone->cloneMembers(this, newManager);
	clone->drop();
	return (clone);
}

void								irr::scene::MySceneNode::OnRegisterSceneNode()
{
	if (IsVisible)
		SceneManager->registerNodeForRendering(this, irr::scene::ESNRP_SOLID);
	ISceneNode::OnRegisterSceneNode();
}

void								irr::scene::MySceneNode::render()
{
	irr::video::IVideoDriver* driver = SceneManager->getVideoDriver();

	driver->setMaterial(m_material);
	driver->setTransform(irr::video::ETS_WORLD, AbsoluteTransformation);
	driver->draw3DBox(m_box, irr::video::SColor(255, 255, 255, 255));
}

const irr::core::aabbox3d<irr::f32>	&irr::scene::MySceneNode::getBoundingBox() const
{
	return (m_box);
}

irr::u32							irr::scene::MySceneNode::getMaterialCount() const
{
	return (1);
}

irr::video::SMaterial				&irr::scene::MySceneNode::getMaterial(u32 i)
{
	return (m_material);
}

// My methods :
void								irr::scene::MySceneNode::setOffset(const irr::core::vector2d<irr::f32> &offset)
{
	m_offset.X = offset.X;
	m_offset.Y = offset.Y;
}

irr::core::vector2d<irr::f32>		&irr::scene::MySceneNode::getOffset(void)
{
	return (m_offset);
}
