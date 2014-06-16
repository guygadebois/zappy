// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   PartEmitterAnim.cpp                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2014/06/16 12:06:57 by glourdel          #+#    #+#             //
//   Updated: 2014/06/16 14:13:19 by glourdel         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "PartEmitterAnim.h"

PartEmitterAnim::PartEmitterAnim(scene::IParticleSystemSceneNode *system,
								 scene::IParticleRingEmitter *emitter,
								 const u32 now, const u32 time)
	: m_particleSystem(system),
	  m_emitter(emitter),
	  m_initTime(now),
	  m_animTime(time),
	  m_actualHeight(PLANET_RADIUS),
	  m_animEnd(false)
{
	m_actualRadius = m_emitter->getRadius();
}

bool		PartEmitterAnim::update(const u32 now)
{
	if (m_initTime + now >= m_animTime)
	{
		m_animEnd = true;
		m_particleSystem->setPosition(core::vector3df(0.0f, PLANET_RADIUS, 0.0f));
		return (false);
	}
//	m_particleSystem->setPosition(core::vector3df(
//									  0.0f,
//									  PLANET_RADIUS - (2 * PLANET_RADIUS) * (now - m_initTime) / m_animTime,
//									  0.0f));
	return (true);
}
