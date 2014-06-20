/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_forward.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/17 15:41:21 by bjacob            #+#    #+#             */
/*   Updated: 2014/06/20 19:34:37 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "map.h"
#include "types.h"
#include "get_arg.h"
#include "libft.h"
#include <stdio.h>

void		ft_move(t_area ***map, t_trant *trant, int x, int y)
{
	t_list_trant	*lst;
	t_list_trant	*tmp;

	lst = map[trant->x][trant->y]->list_player;
	if (lst->player->sock == trant->sock)
	{
		map[trant->x][trant->y]->list_player =
			map[trant->x][trant->y]->list_player->next;
		trant->x = x;
		trant->y = y;
		add_trant_map(map, trant);
	}
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
	trant->x = x;
	trant->y = y;
}

void		ft_move_forward(t_data *game, t_trant *trant, t_area ***map)
{
	printf("%d %d\n", trant->x, trant->y);
	if (trant->direct == 4 && (trant->x - 1) >= 0)
		ft_move(map, trant, (trant->x - 1), trant->y);
	else if (trant->direct == 4 && (trant->x - 1) < 0)
		ft_move(map, trant, (game->length - 1), trant->y);
	else if (trant->direct == 3 && (trant->y + 1) == game->width)
		ft_move(map, trant, trant->x, 0);
	else if (trant->direct == 3 && (trant->y + 1) != game->width)
		ft_move(map, trant, trant->x, (trant->y + 1));
	else if (trant->direct == 2 && (trant->x + 1) == game->length)
		ft_move(map, trant, 0, trant->y);
	else if (trant->direct == 2 && (trant->x + 1) != game->length)
		ft_move(map, trant, (trant->x + 1), trant->y);
	else if (trant->direct == 1 && (trant->y) > 0)
		ft_move(map, trant, trant->x, (trant->y - 1));
	else if (trant->direct == 1 && (trant->y - 1) < 0)
		ft_move(map, trant, trant->x, game->width - 1);
	printf("%d %d\n", trant->x, trant->y);
	ft_strcpy(trant->cmd_out, "ok\n");
	ft_strstrcat(game->visu.cmd_out, "ppo", 4, trant->sock, trant->x,
			trant->y, trant->direct);
}
