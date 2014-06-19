/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/18 09:58:21 by bjacob            #+#    #+#             */
/*   Updated: 2014/06/18 10:35:02 by bjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "libft.h"

void	ft_turn_right(t_trant *trant)
{
	trant->direct++;
	if (trant->direct == 5)
		trant->direct = 1;
	ft_putendl("ok");
}
