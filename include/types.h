/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcouly <dcouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 17:03:25 by dcouly            #+#    #+#             */
/*   Updated: 2014/06/20 18:17:10 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
#define TYPES_H

# include <sys/select.h>
# include "common.h"
# include "map.h"
# include "libft.h"

typedef struct	s_fds
{
	fd_set	master;
	fd_set	read;
	fd_set	write;
}				t_fds;

typedef struct	s_visu
{
	int		sock;
	char	cmd_in[WORK_BUFSIZE];
	char	cmd_out[BUF_VISU];
}				t_visu;

typedef struct	s_data
{
	int		time;
	int		length;
	int		width;
	t_area	***map;
	t_list	*trant;
	t_visu	visu;
	int		sock;
	int		nbmax;
	t_list	*team;
	int		fd_visu;
}				t_data;

#endif
