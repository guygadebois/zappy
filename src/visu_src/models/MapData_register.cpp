// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   MapData_register.cpp                               :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2014/06/10 16:28:45 by glourdel          #+#    #+#             //
//   Updated: 2014/06/11 15:08:39 by glourdel         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include "MapData.h"
#include "MySceneNode.h"

using namespace std;

void		MapData::registerTrantor(scene::MySceneNode *parentNode,
									 const u32 posX, const u32 posY,
									 const string team)
{
	u32		count;

	count = 0;
	m_trantors.push_back(parentNode);
	m_matrix[posX][posY].trantors.push_back(parentNode);
	for (list<string>::iterator it = m_teams.begin(); it != m_teams.end(); ++it, ++count)
	{
		if (*it == team)
		{
			parentNode->setTeamNbr(count);
			return ;
		}
	}
	parentNode->setTeamNbr(count);
	m_teams.push_back(team);
}

void		MapData::registerItem(scene::MySceneNode *parentNode,
								  const u32 posX, const u32 posY,
								  const u8 itemNbr)
{
	m_matrix[posX][posY].item[itemNbr].push_back(parentNode);
}
