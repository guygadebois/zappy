/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/31 14:10:08 by glourdel          #+#    #+#             */
/*   Updated: 2014/06/02 21:19:54 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include <irrlicht.h>

# define PLANET_RADIUS 45.0f

using namespace irr;

class Engine
{

public:
	Engine();
	~Engine();
	bool	addPlanet();
	bool	addTrantors();
	void	loop();

private:
	IrrlichtDevice					*m_device;
	video::IVideoDriver*			m_driver;
	scene::ISceneManager			*m_sceneManager;
// Objets :
	scene::IAnimatedMeshSceneNode	*m_trentor1;
	scene::ISceneNode				*m_planet;
// Meshes :
	scene::IAnimatedMesh			*m_trentorMesh;
// Textures :
	video::ITexture					*m_planetTexture;
// Images :
	video::IImage					*m_planetGrid;

};

#endif
