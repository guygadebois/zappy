// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   MapData_particles.cpp                              :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2014/06/16 12:05:36 by glourdel          #+#    #+#             //
//   Updated: 2014/06/16 14:15:12 by glourdel         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include "MapData.h"
#include "MySceneNode.h"

using namespace std;

void					MapData::AnimParticleEmitters(const u32 now)
{
	list<PartEmitterAnim *>::iterator	it;

	it = m_partEmitterAnimations.begin();
	while (it != m_partEmitterAnimations.end())
	{
		if ((*it)->update(now) == false)
		{
//			delete (*it);
//			it = m_partEmitterAnimations.erase(it);
//		}
//		else
			++it;
	}
}
