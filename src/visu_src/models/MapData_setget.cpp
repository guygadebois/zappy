// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   MapData_setget.cpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2014/06/09 15:31:30 by glourdel          #+#    #+#             //
//   Updated: 2014/06/18 15:07:39 by glourdel         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include "MySceneNode.h"

using namespace std;

core::dimension2d<u32>	MapData::getGridSize()
{
	return (m_gridSize);
}

core::dimension2d<u32>	MapData::getTexturePSize()
{
	return (m_texturePSize);
}

core::dimension2d<u32>	MapData::getGridElemPSize()
{
	return (m_gridElemPSize);
}

void					MapData::setMatrixSquareInit(u32 x, u32 y, bool toSet)
{
	m_matrix[x][y].init = toSet;
}

u32						MapData::getTimeUnit(void)
{
	return (m_timeUnit);
}

void					MapData::setTimeUnit(s32 time)
{
	m_timeUnit = time;
}

scene::MySceneNode		*MapData::getTrantorById(const u32 id, const bool verbose)
{
	list<scene::MySceneNode *>::iterator	it;

	for (it = m_trantors.begin(); it != m_trantors.end(); ++it)
	{
		if ((*it)->getId() == id)
			return (*it);
	}
	if (verbose)
	{
		cout << "MapData::getTrantorByID ERROR -> could not find trantor with id ";
		cout << id << endl;
	}
	return (NULL);
}

list<scene::MySceneNode*>	*MapData::getTrantorsByPos(const core::vector2di &pos)
{
	return (&m_matrix[pos.X][pos.Y].trantors);
}

void						MapData::setMatrixPartSys(
	u32 x, u32 y, scene::IParticleSystemSceneNode *partSys)
{
	m_matrix[x][y].partSys = partSys;
}

scene::IParticleSystemSceneNode	*MapData::getMatrixPartSys(u32 x, u32 y)
{
	return (m_matrix[x][y].partSys);
}
