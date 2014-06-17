/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/31 14:10:08 by glourdel          #+#    #+#             */
/*   Updated: 2014/06/17 13:48:37 by dcouly           ###   ########.fr       */
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

	bool	isReady(void);
	bool	addPlanet(void);
	bool	addTrantor(int id, int X, int Y, int orientation, int level,
					   const string team);
	bool	addTrees(void);
	bool	addLights(void);
	void	loop(void);
	bool	addItem(const u8 itemNbr, const u32 howMany, const u32 x, const u32 y);
// Action suite aux commandes :
	bool	setSquareContent(const string line);
	bool	updateTrantorPosition(const string line);
	bool	newClientConnected(const string line);
	bool	updateTrantorLevel(const string line);
	bool	takeRessource(const string line);
	bool	dropRessource(const string line);
	bool	expulse(const string line);
	bool	broadcast(const string line);
	bool	die(const string line);

private:
	bool	launchBroadcastParticles(scene::MySceneNode *trantor);

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
	scene::IAnimatedMesh			*m_itemMesh[7];
// Textures :
	video::ITexture					*m_planetTexture;
	video::ITexture					*m_trantorTexture[10];
	video::ITexture					*m_gemTexture[7];
// Images :
	video::IImage					*m_planetGrid;
};

#endif
