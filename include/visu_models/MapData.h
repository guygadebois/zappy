/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapData.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/03 15:17:17 by glourdel          #+#    #+#             */
/*   Updated: 2014/06/09 12:42:09 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPDATA_H
# define MAPDATA_H

#include <vector>
#include <list>
#include <string>
#include <irrlicht.h>

using namespace std;
using namespace irr;

namespace irr {
	namespace scene {
		class MySceneNode;
	}
}

typedef struct			s_mapElem
{
	list<scene::MySceneNode *>		trantors;
	list<scene::MySceneNode *>		stones;
	list<scene::MySceneNode *>		food;
}						t_mapElem;

typedef struct			s_animation
{
	scene::MySceneNode				*parentNode;
	scene::ISceneNodeAnimator		*anim;
	core::vector3df					fromRotation;
	core::vector3df					rotation;
	int								diveState;
}						t_animation;

class MapData
{
public:
	MapData(u32 width, u32 height, u32 textWidth = 4000, u32 textHeight = 2000);
	core::dimension2d<u32>		getGridSize();
	core::dimension2d<u32>		getTexturePSize();
	core::dimension2d<u32>		getGridElemPSize();
	void						registerAnimation(scene::MySceneNode *parentNode,
												  scene::ISceneNodeAnimator *anim,
												  const core::vector3df &oldRotation,
												  const core::vector3df &rotation,
												  int diveState=-1);
	void						checkAnimationsEnd(void);
	static bool					rotationAtEnd(const core::vector3df &rotation,
											  const core::vector3df &actualRotation,
											  const core::vector3df &fromRotation);
	void						registerTrantor(scene::MySceneNode *parentNode,
												u32 posX, u32 posY, const char *team);
	void						updatePosition(scene::MySceneNode *parentNode,
											   const core::vector2di &newPos);

private:
	vector<vector<t_mapElem> >	m_matrix;
	core::dimension2d<u32>		m_gridSize; // Number of elem in the grip
	core::dimension2d<u32>		m_texturePSize; // Pixel-size of the texture
	core::dimension2d<u32>		m_gridElemPSize; // Pixel-size of an elem on the texture
	list<t_animation *>			m_animations;
	list<scene::MySceneNode *>	m_trantors;
	list<string>				m_teams;
};

#endif
