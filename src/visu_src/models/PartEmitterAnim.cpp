// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   PartEmitterAnim.cpp                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2014/06/16 12:06:57 by glourdel          #+#    #+#             //
//   Updated: 2014/06/16 14:41:49 by glourdel         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "PartEmitterAnim.h"
#include <cmath>

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
	f32		radius;
	f32		x;
	f32		y;
	f32		elapsedTime;

	elapsedTime = static_cast<f32>(now) - static_cast<f32>(m_initTime);
	if (m_initTime + now >= m_animTime)
	{
		m_animEnd = true;
		m_emitter->setCenter(core::vector3df(0.0f, PLANET_RADIUS, 0.0f));
		return (false);
	}
	m_emitter->setCenter(core::vector3df(
							 0.0f,
							 PLANET_RADIUS - (2 * PLANET_RADIUS + 6.0f) * elapsedTime / static_cast<f32>(m_animTime),
							 0.0f));
	x = 1.0f - (2.0f * elapsedTime / static_cast<f32>(m_animTime));
	y = cos(asin(x));
	radius = y * PLANET_RADIUS;
	m_emitter->setRadius(radius);
	return (true);
}
