/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/31 14:10:08 by glourdel          #+#    #+#             */
/*   Updated: 2014/06/24 17:07:54 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include <irrlicht.h>
# include "MySceneNode.h"
# include "MapData.h"
# include "visu_define.h"
# include "VisuComm.h"

using namespace irr;

class VisuComm;
class MapData;
namespace irr {
	namespace scene {
		class MySceneNode;
	}
}

class Engine
{

public:
	Engine(MapData *mapData, VisuComm *visuComm);
	~Engine(void);

	bool	start(void);
	bool	isStarted(void) const;
	bool	addPlanet(void);
	bool	addTrantor(int id, u32 X, u32 Y, u8 orientation, u8 level,
					   const string team);
	bool	addEgg(int id, u32 X, u32 Y, f32 offsetX, f32 offsetY,
				   const string team);
	bool	addTrees(void);
	bool	addLights(void);
	void	loop(VisuComm *visuComm);
	bool	addItem(const u8 itemNbr, const u32 howMany, const u32 x, const u32 y);
// Action suite aux commandes :
	bool	treatCmd(const string line);
	bool	setTimeUnit(const string line);
	bool	setSquareContent(const string line);
	bool	newClientConnected(const string line);
	bool	updateTrantorPosition(const string line);
	bool	updateTrantorLevel(const string line);
	bool	takeRessource(const string line);
	bool	dropRessource(const string line);
	bool	expulse(const string line);
	bool	broadcast(const string line);
	bool	die(const string line);
	bool	startIncantation(const string line);
	bool	endIncantation(const string line);
	bool	deliverEgg(const string line);
	bool	eggDelivered(const string line);
	bool	eggHatchOut(const string line);
	bool	endOfGame(const string line);
	bool	itemRegenerate(const string line);

private:
	bool	launchBroadcastParticles(scene::MySceneNode *trantor);
	bool	startIncantationParticles(u32 posX, u32 posY);

	IrrlichtDevice					*m_device;
	video::IVideoDriver				*m_driver;
	scene::ISceneManager			*m_sceneManager;
	scene::ICameraSceneNode			*m_camera;
	MapData							*m_mapData;
	VisuComm						*m_visuComm;
	bool							m_started;
// Objets :
	scene::MySceneNode				*m_emptyParent;
	scene::ISceneNode				*m_planet;
// Meshes :
	scene::IAnimatedMesh			*m_trentorMesh;
	scene::IAnimatedMesh			*m_treeMesh;
	scene::IAnimatedMesh			*m_eggMesh;
	scene::IAnimatedMesh			*m_itemMesh[7];
// Textures :
	video::ITexture					*m_planetTexture;
	video::ITexture					*m_trantorTexture[10];
	video::ITexture					*m_gemTexture[7];
	video::ITexture					*m_particleTexture1;
	video::ITexture					*m_particleTexture2;
// Images :
	video::IImage					*m_planetGrid;
// GUI :
	gui::IGUIEnvironment			*m_gui;
};

#endif
