// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   mystring.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2014/06/09 15:52:49 by glourdel          #+#    #+#             //
//   Updated: 2014/06/09 16:05:51 by glourdel         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <sstream>
#include "mystring.h"

vector<string>		*mystring::strsplit(const string str)
{
	vector<string>	*tokens;
	stringstream	ss(str);
	string			buf;

	tokens = new vector<string>;
	if (tokens == NULL)
		return (NULL);
	while (ss >> buf)
		tokens->push_back(buf);
	return (tokens);
}
