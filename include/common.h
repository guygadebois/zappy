/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcouly <dcouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 16:33:15 by dcouly            #+#    #+#             */
/*   Updated: 2014/06/12 16:01:39 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# define BUFSIZE 1024
# define WORK_BUFSIZE 1024
# define BUF_VISU 16384

char*	read_buf(char *buf);
int		find_ret(char *str);
int		cl_new_connection(char *ip, char *port, char *name);

#endif
