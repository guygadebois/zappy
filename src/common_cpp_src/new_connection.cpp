/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_connection.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcouly <dcouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/10 15:14:35 by dcouly            #+#    #+#             */
/*   Updated: 2014/06/11 14:01:01 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <arpa/inet.h>
#include <netdb.h>
#include <cstring>
#include "common.h"

using namespace std;

int		cl_new_connection(char *ip, char *port, char *name)
{
	struct protoent		*proto;
	int					sock;
	struct sockaddr_in	sin;
	int					v;
	char				buf[11];

	proto = getprotobyname("tcp");
	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	cout << sock << endl;
	sin.sin_family = AF_INET;
	sin.sin_port = htons(atoi(port));
	sin.sin_addr.s_addr = inet_addr(ip);
	if ((v = connect(sock, (const struct sockaddr *)&sin, sizeof(sin))) == -1)
	{
		cout << "CONNECTION ERROR" << endl;
		exit(-1);
	}
	recv(sock, buf, 10, 0);
	buf[10] = 0;
	cout << buf << endl;
	send(sock, name, strlen(name), 0);
	return (sock);
}
