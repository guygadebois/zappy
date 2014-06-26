/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vision_bis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcouly <dcouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 15:16:15 by dcouly            #+#    #+#             */
/*   Updated: 2014/06/26 18:38:09 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "types.h"
#include "server.h"

t_case	*ft_case(int nb_case, t_data *game, int x, int y)
{
	t_case	*cas;

	cas = malloc(sizeof(t_case));
	if (cas)
	{
		cas->nb = nb_case;
		cas->contenu_case = game->map[x][y];
	}
	return (cas);
}

int		stat_lvl_vision(int opt, int lvl)
{
	static int	lvl_m;

	if (opt)
		lvl_m = lvl;
	return (lvl_m);
}

t_list	*cas_pair(t_data *game, int x, int y)
{
	int			nb_case;
	int			len;
	t_list		*cases;
	t_case		*cas;
	int			lvl;

	lvl = stat_lvl_vision(0, 0);
	cases = NULL;
	len = ((lvl + 1) * 2) - 1;
	nb_case = lvl * lvl;
	cases = ft_lstnew(cases, 1);
	while (len > 0)
	{
		cas = ft_case(nb_case, game, x, y);
		ft_lstpushback(&cases, cas, sizeof(t_case));
		y = (y + 1) % game->width;
		nb_case++;
		len--;
	}
	return (cases);
}

t_list	*cas_impair(t_data *game, int x, int y)
{
	int			nb_case;
	int			len;
	t_list		*cases;
	t_case		*cas;
	int			lvl;

	lvl = stat_lvl_vision(0, 0);
	cases = NULL;
	len = ((lvl + 1) * 2) - 1;
	nb_case = lvl * lvl;
	cases = ft_lstnew(cases, 1);
	while (len > 0)
	{
		cas = ft_case(nb_case, game, x, y);
		ft_lstpushback(&cases, cas, sizeof(t_case));
		x = (x + 1) % game->length;
		nb_case++;
		len--;
	}
	return (cases);
}

t_list	*ft_view(t_data *game, t_trant *trant, int x, int y)
{
	if (trant->direct == 2 || trant->direct == 4)
		return (cas_pair(game, x, y));
	else
		return (cas_impair(game, x, y));
}
