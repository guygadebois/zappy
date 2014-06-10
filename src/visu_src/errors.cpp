// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   errors.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2014/06/10 16:43:30 by glourdel          #+#    #+#             //
//   Updated: 2014/06/10 16:44:10 by glourdel         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>

using namespace std;

bool			err_msg(const char *msg)
{
	cout << msg << endl;
	return (false);
}
