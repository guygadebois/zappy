/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/31 14:10:08 by glourdel          #+#    #+#             */
/*   Updated: 2014/06/04 21:56:59 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include <irrlicht.h>
# include "MapData.h"

# define PLANET_RADIUS 145.0f

using namespace irr;

class Engine
{

public:
	Engine(MapData *mapData);
	~Engine();
	bool	addPlanet();
	bool	addTrantors();
	bool	addTrees();
	void	loop();
	void	relativeRotate(scene::ISceneNode *node, const core::vector3df &rotation);

private:
	IrrlichtDevice					*m_device;
	video::IVideoDriver*			m_driver;
	scene::ISceneManager			*m_sceneManager;
	scene::ICameraSceneNode			*m_camera;
	MapData							*m_mapData;
// Objets :
	scene::ISceneNode				*m_emptyParent;
	scene::IAnimatedMeshSceneNode	*m_trentor1;
	scene::ISceneNode				*m_planet;
// Meshes :
	scene::IAnimatedMesh			*m_trentorMesh;
	scene::IAnimatedMesh			*m_treeMesh;
// Textures :
	video::ITexture					*m_planetTexture;
// Images :
	video::IImage					*m_planetGrid;

};

#endif
