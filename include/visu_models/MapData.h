/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapData.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/03 15:17:17 by glourdel          #+#    #+#             */
/*   Updated: 2014/06/03 16:42:03 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPDATA_H
# define MAPDATA_H

#include <vector>
#include <irrlicht.h>

using namespace std;
using namespace irr;

typedef struct			s_mapElem
{
	core::vector3df	middle; // 3D coordinate of the middle point of the elem
}						t_mapElem;

class MapData
{
public:
	MapData(u32 width, u32 height, u32 textWidth = 4000, u32 textHeight = 2000);
	core::dimension2d<u32>		getGridSize();
	core::dimension2d<u32>		getTexturePSize();
	core::dimension2d<u32>		getGridElemPSize();
	vector<vector<t_mapElem> >	m_matrix;

private:
	core::dimension2d<u32>		m_gridSize; // Number of elem in the grip
	core::dimension2d<u32>		m_texturePSize; // Pixel-size of the texture
	core::dimension2d<u32>		m_gridElemPSize; // Pixel-size of an elem on the texture
};

#endif
