/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcouly <dcouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 17:03:25 by dcouly            #+#    #+#             */
/*   Updated: 2014/06/26 17:28:58 by sbodovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <sys/select.h>
# include "common.h"
# include "map.h"
# include "get_arg.h"
# include "libft.h"

typedef struct	s_case
{
	int			nb;
	t_area		*contenu_case;
}				t_case;

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
	t_arg		*arg;
	int			fd_max;
	int			time;
	int			length;
	int			width;
	t_area		***map;
	t_list		*trant;
	t_visu		visu;
	int			sock;
	int			nbmax;
	t_list		*team;
	int			fd_visu;
	int			lvl_max;
}				t_data;

#endif
