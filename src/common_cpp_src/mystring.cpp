// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   mystring.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2014/06/09 15:52:49 by glourdel          #+#    #+#             //
//   Updated: 2014/06/19 17:46:29 by glourdel         ###   ########.fr       //
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

int					mystring::StringToWString(std::wstring &ws, const std::string &s)
{
	std::wstring wsTmp(s.begin(), s.end());

	ws = wsTmp;
	return 0;
}
