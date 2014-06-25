/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_deraumere.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 16:53:32 by bjacob            #+#    #+#             */
/*   Updated: 2014/06/25 16:54:00 by bjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include <stdlib.h>
#include <time.h>

void		ft_place_deraumere(t_area ***map, int x, int y, int nb)
{
	int		i;

	i = 0;
	srand(time(0));
	while (i < nb)
	{
		map[rand() % x][rand() % y]->deraumere++;
		i++;
	}
}
