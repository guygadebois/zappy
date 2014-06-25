/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kick.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 10:33:36 by bjacob            #+#    #+#             */
/*   Updated: 2014/06/25 22:36:13 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "get_arg.h"
#include "libft.h"

static int		orientation(int opt, int ori)
{
	static int	oris;

	if (opt)
		oris = ori;
	return (oris);
}

t_list_trant	*ft_save_player(t_area ***map, t_trant *trant)
{
	t_list_trant	*tmp;

	tmp = map[trant->x][trant->y]->list_player;
	while (tmp)
	{
		if (tmp->player->sock == trant->sock)
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}

void			ft_move_other(t_area ***map, t_trant *trant, int x, int y)
{
	t_list_trant	*save;
	t_list_trant	*cur;
	t_list_trant	*nxt;

	save = ft_save_player(map, trant);
	cur = map[trant->x][trant->y]->list_player;
	nxt = cur->next;
	while (cur)
	{
		if (cur->player->sock != trant->sock)
		{
			cur->next = map[x][y]->list_player;
			map[x][y]->list_player = cur;
			cur->player->x = x;
			cur->player->y = y;
			ft_strcat(cur->player->cmd_out, "deplacement ");
			ft_strcat(cur->player->cmd_out, ft_itoa(orientation(0, 0)));
			ft_strcat(cur->player->cmd_out, "\n");
		}
		cur = nxt;
		if (cur)
			nxt = cur->next;
	}
	save->next = NULL;
	map[trant->x][trant->y]->list_player = save;
}

void			ft_kick(t_arg *game, t_area ***map, t_trant *trant)
{
	if (trant->direct == 4)
		orientation(1, 2);
	else if (trant->direct == 3)
		orientation(1, 1);
	else
		orientation(1, trant->direct + 2);
	if (trant->direct == 4 && (trant->x - 1) >= 0)
		ft_move_other(map, trant, (trant->x - 1), trant->y);
	else if (trant->direct == 4 && (trant->x - 1) < 0)
		ft_move_other(map, trant, (game->height - 1), trant->y);
	else if (trant->direct == 3 && (trant->y + 1) == game->width)
		ft_move_other(map, trant, trant->x, 0);
	else if (trant->direct == 3 && (trant->y + 1) != game->width)
		ft_move_other(map, trant, trant->x, (trant->y + 1));
	else if (trant->direct == 2 && (trant->x + 1) == game->height)
		ft_move_other(map, trant, 0, trant->y);
	else if (trant->direct == 2 && (trant->x + 1) != game->height)
		ft_move_other(map, trant, (trant->x + 1), trant->y);
	else if (trant->direct == 1 && (trant->y) > 0)
		ft_move_other(map, trant, trant->x, (trant->y - 1));
	else if (trant->direct == 1 && (trant->y - 1) < 0)
		ft_move_other(map, trant, trant->x, game->width - 1);
	ft_strcat(trant->cmd_out, "ok\n");
}
