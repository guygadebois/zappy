/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 17:19:46 by glourdel          #+#    #+#             */
/*   Updated: 2014/06/23 17:21:29 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

int			cl_err_usage(void);
bool		cl_parse_line(int ac, char **av, char **addr, char **port,
						char **team);

#endif
