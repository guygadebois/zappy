// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   VisuComm.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2014/06/20 18:31:22 by glourdel          #+#    #+#             //
//   Updated: 2014/06/20 18:31:23 by glourdel         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <irrlicht.h>
#include <iostream>
#include <stdlib.h>
#include "common.h"
#include "mystring.h"
#include "VisuComm.h"

VisuComm::VisuComm(MapData *&mapData, Engine *&engine, int sock)
	: m_engine(engine),
	  m_mapData(mapData),
	  m_sock(sock),
	  m_workBuf(""),
	  m_firstCmd(true)
{
}

size_t			VisuComm::find_ret(const string &str)
{
	size_t	found;

	found = str.find("\n");
	return (found);
}

string			VisuComm::getCmdBuf(void)
{
	size_t	nb_char;
	string	cmd;

	if ((nb_char = find_ret(m_workBuf)) != string::npos)
	{
		cmd = m_workBuf;
		cmd.resize(nb_char);
		m_workBuf = m_workBuf.substr(nb_char + 1, m_workBuf.size() - nb_char - 1);
//		cout << "CMD que je retourne : " << cmd << endl;
		return (cmd);
	}
	return ("");
}


static MapData	*setMap(const string line)
{
	vector<string>	*tokens;
	MapData			*map;

	tokens = mystring::strsplit(line);
	map = new MapData(stoi((*tokens)[1]), stoi((*tokens)[2]));
	delete(tokens);
	return (map);
}

bool			VisuComm::launchOnce(void)
{
	string			tmp;
	string			cmd;
	int				nb_char;

	FD_ZERO(&m_read_fd);
	FD_SET(m_sock, &m_read_fd);
	FD_ZERO(&m_write_fd);
	FD_SET(1, &m_write_fd);
	if (select(m_sock + 1, &(m_read_fd), &(m_write_fd), NULL, NULL) == -1)
	{
		cout << "Error Select" << endl;
		return (false);
	}
	if (FD_ISSET(m_sock, &m_read_fd))
	{
		nb_char = recv(m_sock, m_buf, 1023, 0);
		m_buf[nb_char] = 0;
		tmp = strdup(m_buf);
		m_workBuf = m_workBuf + tmp;
//		cout << "Workbuf = " << m_workBuf << endl;
	}
	if ((cmd = getCmdBuf()) != "")
	{
		// verifier qu'il s'agit bien de la cmde "msz"
		if (m_firstCmd)
		{
			m_firstCmd = false;
			m_mapData = setMap(cmd);
			m_engine = new Engine(m_mapData);
		}
		else
		{
			m_engine->treatCmd(cmd);
			if (m_engine->isStarted() == false && m_mapData->isReady() == true)
			{
				cout << "I'm ready to go !!!!!!\n";
				m_engine->start();
			}
		}
	}
	return (true);
}

bool			VisuComm::getMapData(void)
{
	while (m_engine == NULL || m_engine->isStarted() == false)
		launchOnce();
	return (true);
}
