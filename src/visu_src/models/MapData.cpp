// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   MapData.cpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2014/06/03 15:25:43 by glourdel          #+#    #+#             //
//   Updated: 2014/06/03 16:51:39 by glourdel         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "MapData.h"

MapData::MapData(u32 width, u32 height, u32 textWidth, u32 textHeight) : m_texturePSize(textWidth, textHeight), m_gridSize(width, height), m_matrix(width, vector<t_mapElem>(height))
{
	m_gridElemPSize.Width = m_texturePSize.Width / width;
	m_gridElemPSize.Height = m_texturePSize.Height / height;
// Init matrix
	for (int i = 0; i < m_gridSize.Width; i++)
	{
		for (int j = 0; j < m_gridSize.Height; j++)
		{
			m_matrix[i][j].middle.X = (float)i * 6;
			m_matrix[i][j].middle.Y = 45.0f;
			m_matrix[i][j].middle.Z = (float)j * 6;
		}
	}
}

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
