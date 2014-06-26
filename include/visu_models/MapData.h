/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapData.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/03 15:17:17 by glourdel          #+#    #+#             */
/*   Updated: 2014/06/26 11:22:17 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPDATA_H
# define MAPDATA_H

#include <vector>
#include <list>
#include <string>
#include <irrlicht.h>
#include "PartEmitterAnim.h"
#include "Engine.h"

using namespace std;
using namespace irr;

namespace irr {
	namespace scene {
		class MySceneNode;
	}
}

class Engine;

typedef struct			s_mapElem
{
	list<scene::MySceneNode *>		trantors;
	list<scene::MySceneNode *>		item[7];
	scene::IParticleSystemSceneNode	*partSys;
	bool							init;
}						t_mapElem;

typedef struct			s_animation
{
	scene::MySceneNode				*parentNode;
	scene::ISceneNodeAnimator		*anim;
	core::vector3df					fromRotation;
	core::vector3df					rotation;
	int								diveState;
}						t_animation;

typedef struct			s_frameAnimation
{
	scene::MySceneNode				*parentNode;
	u32								begFrame;
	u32								endFrame;
	u32								nextBeginLoopFrame;
	u32								nextEndLoopFrame;
	u8								nextFrameSpeed;
	u32								loopNbr;
	bool							hideObjectAtEnd;
	scene::MySceneNode				*objectToHide;
}						t_frameAnimation;

class MapData
{
public:
	MapData(u32 width, u32 height);
	void						registerAnimation(scene::MySceneNode *parentNode,
												  scene::ISceneNodeAnimator *anim,
												  const core::vector3df &oldRotation,
												  const core::vector3df &rotation,
												  int diveState=-1);
	void						registerFrameAnimation(scene::MySceneNode *parentNode,
													   u32 begFrame,
													   u32 endFrame,
													   u32 nextBeginLoopFrame,
													   u32 nextEndLoopFrame,
													   u8 nextFrameSpeed=5,
													   u8 loopNbr=1,
													   bool hideObjectAtEnd=false,
													   scene::MySceneNode *objectToHide=NULL);
	void						checkAnimationsEnd(void);
	static bool					rotationAtEnd(const core::vector3df &rotation,
											  const core::vector3df &actualRotation,
											  const core::vector3df &fromRotation);
	void						registerTrantor(scene::MySceneNode *parentNode,
												const u32 posX, const u32 posY,
												const string team);
	void						registerItem(scene::MySceneNode *parentNode,
											 const u32 posX, const u32 posY,
											 const u8 itemNbr);
	void						updatePosition(scene::MySceneNode *parentNode,
											   const core::vector2di &newPos);
	void						removeDeadTrantor(scene::MySceneNode *parentNode);
	bool						knowAllSquares(void) const;
	bool						isReady(void) const;
	scene::MySceneNode			*pickItemFromList(const u32 itemNbr, const core::vector2di &boardPos);
	scene::MySceneNode			*pickFreeItem(const u32 itemNbr, const core::vector2di &boardPos);
	void						registerPartEmitterAnim(PartEmitterAnim *anim);
	void						AnimParticleEmitters(const u32 now);
	void						hideItemsOnInoccupiedSquares(void);
	bool						addFoodOnSquare(Engine *engine, const u32 posX, const u32 posY);
	bool						throwGemAfterBroadcast(const u8 itemNbr,
													   const u32 toX, const u32 toY);

	// Accesseur
	core::dimension2d<u32>		getGridSize();
	core::dimension2d<u32>		getTexturePSize();
	core::dimension2d<u32>		getGridElemPSize();
	void						setMatrixSquareInit(u32 x, u32 y, bool toSet);
	u32							getTimeUnit(void);
	void						setTimeUnit(s32 time);
	scene::MySceneNode			*getTrantorById(const u32 id, const bool verbose=true);
	list<scene::MySceneNode*>	*getTrantorsByPos(const core::vector2di &pos);
	void						setMatrixPartSys(
		u32 x, u32 y, scene::IParticleSystemSceneNode *partSys);
	scene::IParticleSystemSceneNode	*getMatrixPartSys(u32 x, u32 y);
	void						setEndOfGame(const string winnerTeam);

private:
	void						checkFrameAnimationsEnd(void);
	void						checkDiveAnimationsEnd(void);
	static void					hideItem(scene::MySceneNode *item);
	static void					showItem(scene::MySceneNode *item);

	vector<vector<t_mapElem> >	m_matrix;
	core::dimension2d<u32>		m_gridSize; // Number of elem in the grip
	core::dimension2d<u32>		m_texturePSize; // Pixel-size of the texture
	core::dimension2d<u32>		m_gridElemPSize; // Pixel-size of an elem on the texture
	list<t_animation *>			m_animations;
	list<scene::MySceneNode *>	m_trantors;
	list<scene::MySceneNode *>	m_freeItem[7];
	list<string>				m_teams;
	s32							m_timeUnit;
	list<t_frameAnimation *>	m_pickAnimations;
	list<PartEmitterAnim *>		m_partEmitterAnimations;
	bool						m_endOfGame;
	string						m_winnerTeam;
};

#endif
