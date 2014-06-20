/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/18 09:58:21 by bjacob            #+#    #+#             */
/*   Updated: 2014/06/20 17:25:59 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "libft.h"

void	ft_turn_right(t_trant *trant)
{
	trant->direct++;
	trant->direct %= 4;
	ft_putendl("ok");
}
