/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MySceneNode.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/05 17:45:38 by glourdel          #+#    #+#             */
/*   Updated: 2014/06/05 19:05:10 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYSCENENODE_H
# define MYSCENENODE_H

# include <irrlicht.h>

namespace irr
{
	namespace scene
	{

		class MySceneNode : public irr::scene::ISceneNode
		{
		public:
			// Irr obligatory methods :
			MySceneNode(irr::scene::ISceneNode* parent,
						irr::scene::ISceneManager* mgr, s32 id = 0);
			virtual irr::scene::ISceneNode	*clone(irr::scene::ISceneNode *newParent=0, irr::scene::ISceneManager *newManager=0);
			virtual void OnRegisterSceneNode();
			virtual void render();
			virtual const irr::core::aabbox3d<irr::f32>& getBoundingBox() const;
			virtual irr::u32 getMaterialCount() const;
			virtual irr::video::SMaterial& getMaterial(irr::u32 i);

			// My methods :
			void						setOffset(const irr::core::vector2d<f32> &offset);
			irr::core::vector2d<f32>	&getOffset(void);

		private:
			// Irr obligatory attributes :
			irr::core::aabbox3d<irr::f32>	m_box;
			irr::video::SMaterial			m_material;

			// My attributes :
			irr::core::vector2d<irr::f32>	m_offset;
		};
	}
}

#endif
