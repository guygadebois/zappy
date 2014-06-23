/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vision.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbodovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/22 16:19:07 by sbodovsk          #+#    #+#             */
/*   Updated: 2014/06/23 17:37:23 by sbodovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "server.h"

#include <unistd.h>
#include <stdlib.h>

typedef struct		s_case
{
	int				nb;
	t_area			*contenu_case;	
}					t_case;

static char	*ft_strstrjoin(int nb, ...)
{
	va_list		ap;
	char		*str;
	char		*ptr;
	char		*tmp;

	va_start(ap, nb);
	ptr = ft_strnew(1);
	if (ptr == NULL || nb < 0)
		return (NULL);
	while (nb > 0)
	{
		str = ft_strdup(va_arg(ap, char *));
		tmp = ptr;
		ptr = ft_strjoin(tmp, str);
		free(str);
		free(tmp);
		nb--;
	}
	va_end(ap);
	return (ptr);
}

t_case	*ft_case(int nb_case, t_data *game, int x, int y)
{
	t_case			*cas;

	cas = malloc(sizeof(t_case));
	if (cas)
	{
		cas->nb = nb_case;
		cas->contenu_case = game->map[x][y];
	}
	return (cas);
}

t_list	*ft_view(t_data *game, t_trant *trant, int x, int y, int lvl)
{
	int			nb_case;
	int			len;
	t_list		*cases;
	t_case		*cas;

	len = ((lvl + 1) * 2) -1;
	nb_case = lvl * lvl;
	cases = ft_lstnew(cases, 1);
	if (trant->direct == 2 || trant->direct == 4)
	{
		while (len > 0)
		{
			cas = ft_case(nb_case, game, x, y);
			ft_lstpushback(&cases, cas, sizeof(t_case));
			y = y + 1 % game->width;
			nb_case++;
			len--;
		}
	}
	else
	{
		while (len > 0)
		{
			cas = ft_case(nb_case, game, x, y);
			ft_lstpushback(&cases, cas, sizeof(t_case));
			x = x + 1 % game->length;
			nb_case++;
			len--;
		}

	}
	return (cases);
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
		{
			while (temp.food > 0)
			{
				rep = ft_strstrjoin(2, rep, "nourriture ");
				temp.food--;
			}
			while (temp.linemate > 0)
			{
				rep = ft_strstrjoin(2, rep, "linemate ");
				temp.linemate--;
			}
			while (temp.deraumere > 0)
			{
				rep = ft_strstrjoin(2, rep, "deraumere ");
				temp.deraumere--;
			}
			while (temp.sibur > 0)
			{
				rep = ft_strstrjoin(2, rep, "sibur ");
				temp.sibur--;
			}
			while (temp.mendiane > 0)
			{
				rep = ft_strstrjoin(2, rep, "mendiane ");
				temp.mendiane--;
			}
			while (temp.phiras > 0)
			{
				rep = ft_strstrjoin(2, rep, "phiras ");
				temp.phiras--;
			}
			while (temp.thystame > 0)
			{
				rep = ft_strstrjoin(2, rep, "thystame ");
				temp.thystame--;
			}
			while (temp.list_player != NULL)
			{
				if (trant->sock != temp.list_player->player->sock)
					rep = ft_strstrjoin(2, rep, "player ");
				temp.list_player = temp.list_player->next;
			}
		}
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
		x = trant->x - lvl;
		if (x < 0)
			x = game->length + x;
		y = trant->y - lvl;
		if (y < 0)
			y = game->width + y;
		cases = ft_view(game, trant, x, y, lvl);
		lvl--;
	}
	ft_lstpushback(&cases, ft_case(0, game, trant->x, trant->y), 1);
	rep = ft_rep(cases, trant);
	ft_strcat(trant->cmd_out, rep);
	free(rep);
	return (0);
}
