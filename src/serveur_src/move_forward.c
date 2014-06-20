/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_forward.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/17 15:41:21 by bjacob            #+#    #+#             */
/*   Updated: 2014/06/20 08:28:09 by bjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "get_arg.h"
#include "libft.h"

void		ft_move(t_area ***map, t_trant *trant, int x, int y)
{
	t_list_trant	*lst;
	t_list_trant	*tmp;

	lst = map[trant->x][trant->y]->list_player;
	while (lst->next)
	{
		if (lst->next->player->sock == trant->sock)
		{
			tmp = lst->next->next;
			lst->next->next = map[x][y]->list_player;
			map[x][y]->list_player = lst->next;
			lst->next = tmp;
		}
		lst = lst->next;
	}
}

void		ft_move_forward(t_arg *arg, t_trant *trant, t_area ***map)
{
	if (trant->direct == 1 && (trant->x - 1) >= 0)
		ft_move(map, trant, (trant->x - 1), trant->y);
	else if (trant->direct == 1 && (trant->x - 1) < 0)
		ft_move(map, trant, (arg->width - 1), trant->y);
	else if (trant->direct == 2 && (trant->y + 1) == arg->height)
		ft_move(map, trant, trant->x, 0);
	else if (trant->direct == 2 && (trant->y + 1) != arg->height)
		ft_move(map, trant, trant->x, (trant->y + 1));
	else if (trant->direct == 3 && (trant->x + 1) == arg->width)
		ft_move(map, trant, 0, trant->y);
	else if (trant->direct == 3 && (trant->x + 1) != arg->height)
		ft_move(map, trant, (trant->x + 1), trant->y);
	else if (trant->direct == 4 && (trant->y) >= 0)
		ft_move(map, trant, trant->x, (trant->y - 1));
	else if (trant->direct == 4 && (trant->y - 1) < 0)
		ft_move(map, trant, trant->x, 0);
	ft_putendl("ok");
}
