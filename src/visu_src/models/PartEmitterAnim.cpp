// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   PartEmitterAnim.cpp                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2014/06/16 12:06:57 by glourdel          #+#    #+#             //
//   Updated: 2014/06/16 22:49:17 by glourdel         ###   ########.fr       //
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
	f32		dist;
	f32		x;
	f32		y;
	f32		elapsedTime;

	elapsedTime = static_cast<f32>(now) - static_cast<f32>(m_initTime);
	if (m_animEnd == false || m_initTime + now >= m_animTime)
	{
		m_animEnd = true;
		m_emitter->setCenter(core::vector3df(0.0f, PLANET_RADIUS, 0.0f));
//		delete (m_emitter);
		m_particleSystem->clearParticles();
		return (false);
	}
	y = cos(elapsedTime * M_PI / static_cast<f32>(m_animTime));
	dist = (1 - y) * PLANET_RADIUS;
	m_emitter->setCenter(core::vector3df(
							 0.0f,
							 PLANET_RADIUS - dist,
							 0.0f));
	x = sin(elapsedTime * M_PI / static_cast<f32>(m_animTime));
	radius = x * PLANET_RADIUS * 4.0f / 5.5f;
	m_emitter->setRadius(radius);
	return (true);
}
