/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapData.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/03 15:17:17 by glourdel          #+#    #+#             */
/*   Updated: 2014/06/06 16:39:34 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPDATA_H
# define MAPDATA_H

#include <vector>
#include <list>
#include <irrlicht.h>

using namespace std;
using namespace irr;

typedef struct			s_mapElem
{
	list<scene::IAnimatedMeshSceneNode *>	trantors;
	list<scene::IMeshSceneNode *>			stones;
	list<scene::IMeshSceneNode *>			food;
}						t_mapElem;

typedef struct			s_animation
{
	scene::ISceneNode						*parentNode;
	scene::ISceneNodeAnimator				*anim;
	core::vector3df							fromRotation;
	core::vector2df							fromOffset;
	core::vector3df							Rotation;
	core::vector2df							toOffset;
}						t_animation;

class MapData
{
public:
	MapData(u32 width, u32 height, u32 textWidth = 4000, u32 textHeight = 2000);
	core::dimension2d<u32>		getGridSize();
	core::dimension2d<u32>		getTexturePSize();
	core::dimension2d<u32>		getGridElemPSize();
	void						registerAnimation(scene::ISceneNode *parentNode,
												  scene::ISceneNodeAnimator *anim,
												  const core::vector3df &oldRotation,
												  const core::vector2df &oldOffset,
												  const core::vector3df &Rotation,
												  const core::vector2df &newOffset);
	void						checkAnimationsEnd(void);
	vector<vector<t_mapElem> >	m_matrix;

private:
	core::dimension2d<u32>		m_gridSize; // Number of elem in the grip
	core::dimension2d<u32>		m_texturePSize; // Pixel-size of the texture
	core::dimension2d<u32>		m_gridElemPSize; // Pixel-size of an elem on the texture
	list<t_animation *>			m_animations;
};

#endif
