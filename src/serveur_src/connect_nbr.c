/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_nbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 15:18:05 by bjacob            #+#    #+#             */
/*   Updated: 2014/06/24 18:35:38 by bjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "get_arg.h"
#include "libft.h"

void	ft_connect_nbr(t_arg *arg, t_list *trant, char *team)
{
	int		i;
	t_trant	*tmp;

	i = arg->nbmax;
	while (trant)
	{
		tmp = trant->content;
		if (ft_strcmp(tmp->team, team) == 0)
			i--;
		trant = trant->next;
	}
	ft_putendl(ft_itoa(i));
}
