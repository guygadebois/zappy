/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcouly <dcouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 17:03:25 by dcouly            #+#    #+#             */
/*   Updated: 2014/06/07 19:22:14 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
#define TYPES_H

# include <sys/select.h>
# include "common.h"
# include "libft.h"

typedef struct	s_fds
{
	fd_set	master;
	fd_set	read;
	fd_set	write;
}				t_fds;

typedef struct	s_trant
{
	int		sock;
	char	*team;
	char	cmd_in[WORK_BUFSIZE];
	char	cmd_out[WORK_BUFSIZE];
	int		x;
	int		y;
	int		level;
	int		life;
	int		lin;
	int		der;
	int		sib;
	int		men;
	int		phi;
	int 	thy;
}				t_trant;

typedef struct	s_data
{
	t_list	*trant;
	int		sock;
}				t_data;


#endif
