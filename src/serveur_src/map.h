/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 16:25:20 by bjacob            #+#    #+#             */
/*   Updated: 2014/06/07 11:02:08 by bjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct		s_player
{
	int				id;
	int				x;
	int				y;
	char			direct;
	int				level;
	char			*team;
	int				food;
	int				linemate;
	int				deraumere;
	int				sibur;
	int				mendiane;
	int				phiras;
	int				thystame;
}					t_player;

typedef struct		s_list
{
	t_player		*player;
	struct s_list	*next;
}					t_list;

typedef struct		s_area
{
	int				food;
	int				linemate;
	int				deraumere;
	int				sibur;
	int				mendiane;
	int				phiras;
	int				thystame;
	t_list			*list_player;
}					t_area;

#endif
