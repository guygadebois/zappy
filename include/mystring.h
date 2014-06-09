/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mystring.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/09 15:53:36 by glourdel          #+#    #+#             */
/*   Updated: 2014/06/09 16:05:24 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYSTRING_H
# define MYSTRING_H

# include <string>
# include <vector>

using namespace std;

namespace mystring
{
	vector<string>		*strsplit(const string str);
}

#endif
