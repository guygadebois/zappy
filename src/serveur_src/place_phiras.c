/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_phiras.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 16:56:09 by bjacob            #+#    #+#             */
/*   Updated: 2014/06/25 16:56:13 by bjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include <stdlib.h>
#include <time.h>

void		ft_place_phiras(t_area ***map, int x, int y, int nb)
{
	int		i;

	i = 0;
	srand(time(0));
	while (i < nb)
	{
		map[rand() % x][rand() % y]->phiras++;
		i++;
	}
}
