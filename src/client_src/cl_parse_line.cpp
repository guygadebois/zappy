// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   cl_parse_line.cpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2014/06/23 17:21:02 by glourdel          #+#    #+#             //
//   Updated: 2014/06/23 17:30:47 by glourdel         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <string.h>

bool		cl_parse_line(int ac, char **av, char **addr, char **port,
						char **team)
{
	int		i;

	i = 1;
	*addr = NULL;
	*port = NULL;
	*team = NULL;
	while (i < ac)
	{
		if (strcmp(av[i], "-n") == 0 && i + 1 < ac)
			*team = av[i + 1];
		else if (strcmp(av[i], "-p") == 0 && i + 1 < ac)
			*port = av[i + 1];
		else if (strcmp(av[i], "-h") == 0 && i + 1 < ac)
			*addr = av[i + 1];
		else
			return (false);
		i += 2;
	}
	*addr = *addr == NULL ? strdup("127.0.0.1") : *addr;
	return (*addr && *port);
}
