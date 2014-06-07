/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getclientbysock.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcouly <dcouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 18:59:27 by dcouly            #+#    #+#             */
/*   Updated: 2014/06/07 19:06:57 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "types.h"

t_trant	*sv_getclientbysock(t_data *game, int cs)
{
	t_list	*l;

	l = game->trant;
	while (l)
	{
		if (((t_trant *)l->content)->sock == cs)
			return ((t_trant *)l->content);
		l = l->next;
	}
	return (NULL);
}
