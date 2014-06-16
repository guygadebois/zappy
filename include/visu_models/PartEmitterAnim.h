/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PartEmitterAnim.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/16 12:07:43 by glourdel          #+#    #+#             */
/*   Updated: 2014/06/16 22:25:06 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARTEMITTERANIM_H
# define PARTEMITTERANIM_H

#include <list>
#include <iostream>
#include <irrlicht.h>
#include "visu_define.h"

using namespace std;
using namespace irr;

class PartEmitterAnim
{
public:
	explicit PartEmitterAnim(scene::IParticleSystemSceneNode *system,
							 scene::IParticleRingEmitter *emitter,
							 const u32 now, const u32 time);
	bool		update(const u32 now);

private:
	scene::IParticleSystemSceneNode	*m_particleSystem;
	scene::IParticleRingEmitter		*m_emitter;
	const u32						m_initTime;
	const u32						m_animTime;
	f32								m_actualHeight;
	f32								m_actualRadius;
	bool							m_animEnd;
};

#endif
