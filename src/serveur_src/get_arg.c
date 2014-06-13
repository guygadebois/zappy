/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 08:07:02 by bjacob            #+#    #+#             */
/*   Updated: 2014/06/13 14:38:27 by sbodovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_arg.h"
#include <stdlib.h>

static t_arg	*ft_init_arg(t_arg *arg)
{
	arg = (t_arg *)malloc(sizeof(t_arg));
	arg->port = 0;
	arg->width = 0;
	arg->height = 0;
	arg->nbmax = 0;
	arg->t = 0;
	arg->team = NULL;
	return (arg);
}

static int		ft_valid_param(t_arg *arg)
{
	if (arg->port == 0)
		return (0);
	if (arg->width == 0)
		return (0);
	if (arg->height == 0)
		return (0);
	if (arg->nbmax == 0)
		return (0);
	if (arg->t == 0)
		return (0);
	if (arg->team == NULL)
		return (0);
	return (1);
}

static void		ft_add_team(t_arg *arg, char *team)
{
	t_list		*new;
	t_list		*old;

	new = (t_list *)malloc(sizeof(t_list));
	new->content = team;
	new->next = NULL;
	if (arg->team == NULL)
	{
		arg->team = new;
		return ;
	}
	old = arg->team;
	while (old->next != NULL)
		old = old->next;
	old->next = new;
}

static int		ft_parse(t_arg *arg, int argc, char **argv, int	i)
{
	int		j;

	j = 1;
	if (ft_strcmp(argv[i], "-p") == 0)
		arg->port = ft_atoi(argv[i + 1]);
	else if (ft_strcmp(argv[i], "-x") == 0)
		arg->width = ft_atoi(argv[i + 1]);
	else if (ft_strcmp(argv[i], "-y") == 0)
		arg->height = ft_atoi(argv[i + 1]);
	else if (ft_strcmp(argv[i], "-c") == 0)
		arg->nbmax = ft_atoi(argv[i + 1]);
	else if (ft_strcmp(argv[i], "-t") == 0)
		arg->t = ft_atoi(argv[i + 1]);
	else if (ft_strcmp(argv[i], "-n") == 0)
	{
		while ((i + j) < argc && argv[i + j][0] != '-')
		{
			ft_add_team(arg, argv[i + j]);
			j++;
		}
		j--;
	}
	else
		return (-2);
	return (j);
}

t_arg	*ft_get_arg(int argc, char **argv)
{
	int		i;
	t_arg	*arg;

	i = 1;
	arg = NULL;
	arg = ft_init_arg(arg);
	while (i < argc)
	{
		if ((i + 1) < argc && argv[i][0] == '-' && argv[i + 1][0] != '-')
			i = i + ft_parse(arg, argc, argv, i);
		else
		{
			ft_putendl("ERROR: parsing error.");
			return (NULL);
		}
		i++;
	}
	if (ft_valid_param(arg) == 0)
	{
		ft_putendl("ERROR: missing parameter.");
		return (NULL);
	}
	return (arg);
}
