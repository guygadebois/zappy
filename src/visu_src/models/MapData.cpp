// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   MapData.cpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2014/06/03 15:25:43 by glourdel          #+#    #+#             //
//   Updated: 2014/06/17 17:25:38 by glourdel         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <algorithm>
#include "MapData.h"
#include "Mystring.h"
#include "MySceneNode.h"

using namespace std;

MapData::MapData(u32 width, u32 height, u32 textWidth, u32 textHeight)
	: m_matrix(width, vector<t_mapElem>(height)),
	  m_gridSize(width, height),
	  m_texturePSize(textWidth, textHeight),
	  m_timeUnit(-1)
{
	m_gridElemPSize.Width = m_texturePSize.Width / width;
	m_gridElemPSize.Height = m_texturePSize.Height / height / 2;
// Init matrix
	for (u32 i = 0; i < m_gridSize.Width; i++)
	{
		for (u32 j = 0; j < m_gridSize.Height; j++)
			m_matrix[i][j].init = false;
	}
}

void					MapData::updatePosition(scene::MySceneNode *parentNode,
												const core::vector2di &newPos)
{
	core::vector2di		oldPos;

	oldPos = parentNode->getBoardPos();
	switch (parentNode->getMySceneType())
	{
	case TRANTOR:
		m_matrix[oldPos.X][oldPos.Y].trantors.remove(parentNode);
		m_matrix[newPos.X][newPos.Y].trantors.push_back(parentNode);
		parentNode->setBoardPos(newPos);
		break ;
	//
		// continuer pour les autres types...
	//
	}
}

bool					MapData::knowAllSquares(void) const
{
	for (u32 i = 0; i < m_gridSize.Width; i++)
	{
		for (u32 j = 0; j < m_gridSize.Height; j++)
		{
			if (m_matrix[i][j].init == false)
				return (false);
		}
	}
	return (true);
}

bool					MapData::isReady(void) const
{
	if (m_timeUnit <= 0)
		return (false);
	return (knowAllSquares());
}

scene::MySceneNode		*MapData::pickItemFromList(const u32 itemNbr, const core::vector2di &boardPos)
{
	scene::MySceneNode			*item;
	list<scene::MySceneNode *>	*list;

	if ((list = &m_matrix[boardPos.X][boardPos.Y].item[itemNbr]) && list->size() > 0)
	{
		item = list->front();
		list->pop_front();
		m_freeItem[itemNbr].push_back(item);
		return (item);
	}
	return (NULL);
}

scene::MySceneNode		*MapData::pickFreeItem(const u32 itemNbr, const core::vector2di &boardPos)
{
	scene::MySceneNode			*item;

	if (m_freeItem[itemNbr].size() > 0)
	{
		item = m_freeItem[itemNbr].front();
		m_freeItem[itemNbr].pop_front();
		m_matrix[boardPos.X][boardPos.Y].item[itemNbr].push_back(item);
		return (item);
	}
	return (NULL);
}

void					MapData::hideItem(scene::MySceneNode *item)
{
	item->setVisible(false);
}

void					MapData::hideItemsOnInoccupiedSquares(void)
{
	for (u32 i = 0; i < m_gridSize.Width; i++)
	{
		for (u32 j = 0; j < m_gridSize.Height; j++)
		{
			if (m_matrix[i][j].trantors.size() <= 0)
			{
				for (u8 k = 0; k < 7; k++)
				{
					for_each(m_matrix[i][j].item[k].begin(),
							 m_matrix[i][j].item[k].end(),
							 hideItem);
				}
			}
		}
	}
}
