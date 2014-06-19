/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_inventory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/18 11:01:49 by bjacob            #+#    #+#             */
/*   Updated: 2014/06/18 13:17:52 by bjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "libft.h"

void		ft_get_inventory(t_trant *trant)
{
	char	*res;

	res = ft_strjoin("{", ft_strjoin("nourriture ", ft_atoi(trant->life)));
	res = ft_strjoin(res, ft_strjoin(", linemate ", ft_atoi(trant->lin)));
	res = ft_strjoin(res, ft_strjoin(", deraumere ", ft_atoi(trant->der)));
	res = ft_strjoin(res, ft_strjoin(", sibur ", ft_atoi(trant->sib)));
	res = ft_strjoin(res, ft_strjoin(", mendiane ", ft_atoi(trant->men)));
	res = ft_strjoin(res, ft_strjoin(", phiras ", ft_atoi(trant->phi)));
	res = ft_strjoin(res, ft_strjoin(", thystame ", ft_atoi(trant->thy)));
	res = ft_strjoin(res, "}");
	ft_putendl(res);
}
