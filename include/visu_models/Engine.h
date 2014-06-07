/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/31 14:10:08 by glourdel          #+#    #+#             */
/*   Updated: 2014/06/07 21:55:34 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include <irrlicht.h>
# include "MySceneNode.h"
# include "MapData.h"
# include "visu_define.h"

using namespace irr;

class Engine
{

public:
	Engine(MapData *mapData);
	~Engine(void);
	bool	addPlanet(void);
	bool	addTrantor(int id, int X, int Y, int orientation, int level,
					   const char *team);
	bool	addTrees(void);
	bool	addRocks(void);
	bool	addLights(void);
	void	loop(void);

private:
	IrrlichtDevice					*m_device;
	video::IVideoDriver*			m_driver;
	scene::ISceneManager			*m_sceneManager;
	scene::ICameraSceneNode			*m_camera;
	MapData							*m_mapData;
// Objets :
	scene::MySceneNode				*m_emptyParent;
	scene::ISceneNode				*m_planet;
// Meshes :
	scene::IAnimatedMesh			*m_trentorMesh;
	scene::IAnimatedMesh			*m_treeMesh;
	scene::IAnimatedMesh			*m_rockMesh[6];
// Textures :
	video::ITexture					*m_planetTexture;
// Images :
	video::IImage					*m_planetGrid;

};

#endif
