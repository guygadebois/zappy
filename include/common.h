/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcouly <dcouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 16:33:15 by dcouly            #+#    #+#             */
/*   Updated: 2014/06/10 16:25:39 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# define BUFSIZE 1024
# define WORK_BUFSIZE 1024
# define BUF_VISU 16384

int	cl_new_connection(char *ip, char *port, char *name);

#endif
