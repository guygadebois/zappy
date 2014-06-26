/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_nbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 15:18:05 by bjacob            #+#    #+#             */
/*   Updated: 2014/06/26 09:18:22 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "get_arg.h"
#include "libft.h"

void	ft_connect_nbr(t_arg *arg, t_list *trant, char *team, t_trant *tran)
{
	int		i;
	t_trant	*tmp;

	i = arg->nbmax;
	while (trant)
	{
		tmp = (t_trant *)(trant->content);
		if (ft_strcmp(tmp->team, team) == 0)
			i--;
		trant = trant->next;
	}
	ft_strcat(tran->cmd_out, ft_itoa(i));
	ft_strcat(tran->cmd_out, "\n");
}
