/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MySceneNode.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/05 17:45:38 by glourdel          #+#    #+#             */
/*   Updated: 2014/06/07 17:32:22 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYSCENENODE_H
# define MYSCENENODE_H

# include <irrlicht.h>
# include "MapData.h"
# include "visu_define.h"

using namespace irr;

typedef struct			s_diveBuf
{
	int				state;
	core::vector2di	to;
	core::vector2df	offset;
}						t_diveBuf;

namespace irr
{
	namespace scene
	{

		class MySceneNode : public scene::ISceneNode
		{
		public:
			// Irr obligatory methods :
			MySceneNode(scene::ISceneNode *parent, scene::ISceneManager *mgr,
						MapData *mapData, s32 id=-1);
			virtual scene::MySceneNode			*clone(scene::ISceneNode *newParent=0, scene::ISceneManager *newManager=0);
			virtual void						OnRegisterSceneNode();
			virtual void						render();
			virtual const core::aabbox3d<f32>	&getBoundingBox() const;
			virtual u32							getMaterialCount() const;
			virtual video::SMaterial			&getMaterial(u32 i);

			// My methods :
			scene::IAnimatedMeshSceneNode	*init(scene::IAnimatedMesh *mesh, s32 type,
									 const core::vector2di &boardPos=core::vector2di(0, 0),
									 const u32 itemId=0, const u32 level=0,
									 const s32 orientation=SOUTH, const char *team=NULL);
			bool				uninitialized();
			void				updateOrientation(const s32 newOrientation);
			void				setOffset(const core::vector2d<f32> &offset);
			core::vector2df		&getOffset(void);
			s32					getType(void);
			void				setBoardPos(const core::vector2di &newPos);
			core::vector2di		getBoardPos(void);
			void				rotate(const core::vector3df &rotation);
			void				placeOn(const u32 X, const u32 Y,
										const f32 offsetX=0.5f, const f32 offsetY=0.5f);
			void				moveTo(const core::vector3df &constRotation,
									   const f32 speed=0.1f, const u32 frameStart=40,
									   const u32 frameEnd=45, u32 diveState=-1);
			void				moveToSquare(const u32 X, const u32 Y,
									   const f32 offsetX=0.5f, const f32 offsetY=0.5f,
									   const f32 speed=0.1f, const u32 frameStart=40,
									   const u32 frameEnd=45, u32 diveState=-1);
			void				diveUpTo(const u32 X, const u32 Y,
										 const f32 offsetX=0.5f, const f32 offsetY=0.5f);
			void				diveDownTo(const u32 X, const u32 Y,
										 const f32 offsetX=0.5f, const f32 offsetY=0.5f);
			void				diveContinue();

		private:
			// Irr obligatory attributes :
			core::aabbox3df					m_box;
			video::SMaterial				m_material;

			// My attributes :
			MapData							*m_mapData;
			t_diveBuf						m_diveBuf;
			core::vector2di					m_boardPos;
			core::vector2df					m_offset;
			u32								m_id;
			s32								m_type;
			u32								m_level;
			s32								m_orientation;
			const char						*m_team;
			scene::IAnimatedMeshSceneNode	*m_son;
		};
	}
}

#endif
