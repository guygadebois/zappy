/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 16:27:12 by bjacob            #+#    #+#             */
/*   Updated: 2014/06/10 19:26:14 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include <stdlib.h>
#include <time.h>

static t_area	*ft_init_area(void)
{
	t_area		*area;

	area = (t_area *)malloc(sizeof(t_area));
	area->food = 0;
	area->linemate = 0;
	area->deraumere = 0;
	area->sibur = 0;
	area->mendiane = 0;
	area->phiras = 0;
	area->thystame = 0;
	area->list_player = NULL;
	return (area);
}

void			ft_place_food(t_area ***map, int x, int y, int nb)
{
	int		i;

	i = 0;
	srand(time(0));
	while (i < nb)
	{
		map[rand() % x][rand() % y]->food++;
		i++;
	}
}

static	void	ft_place_mineral(t_area ***map, int x, int y, int nb)
{
	int		i;

	i = 0;
	srand(time(0));
	while (i < nb)
	{
		map[rand() % x][rand() % y]->linemate++;
		map[rand() % x][rand() % y]->deraumere++;
		map[rand() % x][rand() % y]->sibur++;
		map[rand() % x][rand() % y]->mendiane++;
		map[rand() % x][rand() % y]->phiras++;
		map[rand() % x][rand() % y]->thystame++;
		i++;
	}
}

t_area			***ft_create_map(int x, int y, int nb_max)
{
	t_area		***map;
	int			i;
	int			j;

	map = (t_area ***)malloc(sizeof(t_area **) * x);
	i = 0;
	while (i < x)
	{
		j = 0;
		map[i] = (t_area **)malloc(sizeof(t_area *) * y);
		while (j < y)
		{
			map[i][j] = ft_init_area();
			j++;
		}
		i++;
	}
	ft_place_food(map, x, y, (((x * y) / 6) * nb_max));
	ft_place_mineral(map, x, y, (((x * y) / 13) * nb_max));
	return (map);
}
