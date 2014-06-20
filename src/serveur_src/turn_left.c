/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/18 10:35:20 by bjacob            #+#    #+#             */
/*   Updated: 2014/06/20 18:49:14 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "libft.h"

void	ft_turn_left(t_trant *trant)
{
	trant->direct--;
	if (trant->direct == 0)
		trant->direct = 4;
	ft_putendl("ok");
}
