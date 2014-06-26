/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vision.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbodovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/22 16:19:07 by sbodovsk          #+#    #+#             */
/*   Updated: 2014/06/26 15:21:27 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "server.h"

#include <unistd.h>
#include <stdlib.h>

void	ft_concat_all(char **rep, t_area temp)
{
	while (temp.food > 0)
	{
		*rep = ft_strstrjoin(2, *rep, "nourriture ");
		temp.food--;
	}
	while (temp.linemate > 0)
	{
		*rep = ft_strstrjoin(2, *rep, "linemate ");
		temp.linemate--;
	}
	while (temp.deraumere > 0)
	{
		*rep = ft_strstrjoin(2, *rep, "deraumere ");
		temp.deraumere--;
	}
	while (temp.sibur > 0)
	{
		*rep = ft_strstrjoin(2, *rep, "sibur ");
		temp.sibur--;
	}
}

void	ft_concat_allb(char **rep, t_area temp, t_trant *trant)
{
	while (temp.mendiane > 0)
	{
		*rep = ft_strstrjoin(2, *rep, "mendiane ");
		temp.mendiane--;
	}
	while (temp.phiras > 0)
	{
		*rep = ft_strstrjoin(2, *rep, "phiras ");
		temp.phiras--;
	}
	while (temp.thystame > 0)
	{
		*rep = ft_strstrjoin(2, *rep, "thystame ");
		temp.thystame--;
	}
	while (temp.list_player != NULL)
	{
		if (trant->sock != temp.list_player->player->sock)
			*rep = ft_strstrjoin(2, *rep, "player ");
		temp.list_player = temp.list_player->next;
	}
}

void	ft_concat_par(char **rep, t_area temp, t_trant *trant)
{
	ft_concat_all(rep, temp);
	ft_concat_allb(rep, temp, trant);
}

char	*ft_rep(t_list *cases, t_trant *trant)
{
	int		nb_cas;
	int		i;
	char	*rep;
	t_area	temp;
	t_list	*begin;

	i = 0;
	begin = cases;
	nb_cas = (trant->level * trant->level) + ((trant->level + 1) * 2) - 1;
	rep = ft_strstrjoin(1, "{");
	while (i < nb_cas)
	{
		while (((t_case*)cases->content)->nb != i)
			cases = cases->next;
		temp = *((t_case *)cases->content)->contenu_case;
		if (((t_case *)cases->content)->contenu_case != NULL)
			ft_concat_par(&rep, temp, trant);
		i++;
		if (i != nb_cas)
			rep = ft_strstrjoin(2, rep, ", ");
		cases = begin;
	}
	rep = ft_strstrjoin(2, rep, "}");
	return (rep);
}

int		voir(t_data *game, t_trant *trant)
{
	int			lvl;
	int			x;
	int			y;
	t_list		*cases;
	char		*rep;

	lvl = trant->level;
	while (lvl > 0)
	{
		stat_lvl_vision(1, lvl);
		x = trant->x - lvl;
		if (x < 0)
			x = game->length + x;
		y = trant->y - lvl;
		if (y < 0)
			y = game->width + y;
		cases = ft_view(game, trant, x, y);
		lvl--;
	}
	ft_lstpushback(&cases, ft_case(0, game, trant->x, trant->y), 1);
	rep = ft_rep(cases, trant);
	ft_strcat(trant->cmd_out, rep);
	free(rep);
	return (0);
}
