/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_mendiane.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 16:54:45 by bjacob            #+#    #+#             */
/*   Updated: 2014/06/26 14:16:18 by bjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include <stdlib.h>
#include <time.h>

void		ft_place_mendiane(t_data *game, int x, int y, int nb)
{
	int		i;
	int		x_bis;
	int		y_bis;

	i = 0;
	srand(time(0));
	while (i < nb)
	{
		x_bis = rand() % x;
		y_bis = rand() % y;
		game->map[x_bis][y_bis]->mendiane++;
		ft_strcat(game->visu.cmd_out, "ipo 4 ");
		ft_strcat(game->visu.cmd_out, ft_itoa(x_bis));
		ft_strcat(game->visu.cmd_out, " ");
		ft_strcat(game->visu.cmd_out, ft_itoa(y_bis));
		ft_strcat(game->visu.cmd_out, "\n");	
		i++;
	}
}
