// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   MapData_setget.cpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2014/06/09 15:31:30 by glourdel          #+#    #+#             //
//   Updated: 2014/06/09 15:31:43 by glourdel         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "MapData.h"

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
