/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/18 09:58:21 by bjacob            #+#    #+#             */
/*   Updated: 2014/06/20 18:49:26 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "libft.h"

void	ft_turn_right(t_trant *trant)
{
	trant->direct %= 4;
	trant->direct++;
	ft_putendl("ok");
}
