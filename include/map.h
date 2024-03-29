/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 16:25:20 by bjacob            #+#    #+#             */
/*   Updated: 2014/06/26 14:43:30 by bjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <sys/time.h>
# include "common.h"

typedef struct timeval	t_timeval;

typedef struct			s_trant
{
	int					sock;
	char				*team;
	char				cmd_in[WORK_BUFSIZE];
	char				cmd_out[WORK_BUFSIZE];
	char				*current_cmd;
	int					x;
	int					y;
	int					direct;
	int					level;
	int					life;
	struct timeval		t_life;
	int					lin;
	int					der;
	int					sib;
	int					men;
	int					phi;
	int					thy;
	int					fail;
	int					send;
	int					is_oeuf;
	int					nb_oeuf;
	int					is_incan;
	struct timeval		time;
}						t_trant;

typedef struct			s_list_trant
{
	t_trant				*player;
	struct s_list_trant	*next;
}						t_list_trant;

typedef struct			s_area
{
	int					food;
	int					linemate;
	int					deraumere;
	int					sibur;
	int					mendiane;
	int					phiras;
	int					thystame;
	t_list_trant		*list_player;
}						t_area;

#endif
