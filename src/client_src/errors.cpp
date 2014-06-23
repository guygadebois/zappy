// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   errors.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2014/06/23 17:14:28 by glourdel          #+#    #+#             //
//   Updated: 2014/06/23 17:16:24 by glourdel         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>

using namespace std;

int			cl_err_usage(void)
{
	cout << "Usage: ./client -n <team> -p <port> [-h <hostname>]" << endl;
	return (1);
}

