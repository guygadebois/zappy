/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/31 20:50:18 by glourdel          #+#    #+#             */
/*   Updated: 2014/05/31 21:33:12 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include <irrlicht.h>

using namespace irr;

class Engine
{
public:

	Engine();
	~Engine();
	void	addPlanet();
	void	addTrantors();
	void	loop();

private:

	IrrlichtDevice					*m_device;
	video::IVideoDriver				*m_driver;
	scene::ISceneManager			*m_sceneManager;
	scene::IAnimatedMeshSceneNode	*m_trentor1;
	scene::IAnimatedMeshSceneNode	*m_planet;
	scene::IAnimatedMesh			*m_trentorMesh;
	scene::IAnimatedMesh			*m_planetMesh;
	video::ITexture					*m_trentorSkin1;
	video::ITexture					*m_trentorWing1;
	video::ITexture					*m_planetTexture;
};

#endif
