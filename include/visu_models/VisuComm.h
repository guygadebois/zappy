/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VisuComm.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/20 17:56:52 by glourdel          #+#    #+#             */
/*   Updated: 2014/06/20 18:13:46 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUCOMM_H
# define VISUCOMM_H

# include "MapData.h"
# include "Engine.h"
# include <netdb.h>
# include <sys/select.h>

class VisuComm
{
public:
	VisuComm(MapData *&mapData, Engine *&engine, int sock);
	bool			launchOnce(void);
	bool			getMapData(void);

private:
	size_t			find_ret(const string &str);
	string			getCmdBuf(void);

	Engine			*&m_engine;
	MapData			*&m_mapData;
	int				m_sock;
	string			m_workBuf;
	char			m_buf[1024];
	fd_set			m_read_fd;
	fd_set			m_write_fd;
	bool			m_firstCmd;
};

#endif
