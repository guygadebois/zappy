/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 16:25:20 by bjacob            #+#    #+#             */
/*   Updated: 2014/06/09 16:45:30 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "common.h"

typedef struct  s_trant
{
	int		sock;
	char	*team;
	char	cmd_in[WORK_BUFSIZE];
	char	cmd_out[WORK_BUFSIZE];
	int		x;
	int		y;
	int		direct;
	int		level;
	int		life;
	int		lin;
	int		der;
	int		sib;
	int		men;
	int		phi;
	int		thy;
}               t_trant;

typedef struct		s_list_trant
{
	t_trant			*player;
	struct s_list	*next;
}					t_list_trant;

typedef struct		s_area
{
	int				food;
	int				linemate;
	int				deraumere;
	int				sibur;
	int				mendiane;
	int				phiras;
	int				thystame;
	t_list_trant	*list_player;
}					t_area;

#endif
