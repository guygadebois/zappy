/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_in_workbuff.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcouly <dcouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 18:51:09 by dcouly            #+#    #+#             */
/*   Updated: 2014/06/26 10:28:37 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "server.h"
#include "types.h"

static int	sv_time_cmd(char *cmd, t_trant *trant)
{
	if (trant->is_oeuf)
		return (600);
	if (!ft_strcmp(cmd, "avance") || !ft_strcmp(cmd, "droite"))
		return (7);
	if (!ft_strcmp(cmd, "gauche") || !ft_strcmp(cmd, "voir"))
		return (7);
	if (!ft_strcmp(cmd, "inventaire"))
		return (1);
	if (!ft_strncmp(cmd, "prend", 5))
		return (7);
	if (!ft_strncmp(cmd, "pose", 4))
		return (7);
	if (!ft_strcmp(cmd, "expulse"))
		return (7);
	if (!ft_strncmp(cmd, "broadcaster", 11))
		return (7);
	if (!ft_strcmp(cmd, "incantation"))
		return (300);
	if (!ft_strcmp(cmd, "fork"))
		return (42);
	if (!ft_strcmp(cmd, "connect_nbr"))
		return (0);
	return (0);
}

static void	sv_add_time(char *cmd, t_data *game, t_trant *trant)
{
	float	tmp;
	float	micro;
	int		time;

	time = sv_time_cmd(cmd, trant);
	tmp = time;
	tmp = tmp / game->time;
	micro = (tmp - time / game->time) * 1000000;
	time = time / game->time;
	trant->time.tv_usec += micro;
	if (trant->time.tv_usec >= 1000000)
	{
		trant->time.tv_usec %= 1000000;
		time++;
	}
	trant->time.tv_sec += time;
}

void		append_in_workbuf(t_data *game, t_trant *trant, char *buf,
		int rd_oct)
{
	char	*tmp;
	char	*cmd;
	int		offset;

	if (trant == NULL)
		return ;
	ft_strncat(trant->cmd_in, buf, rd_oct);
	while ((offset = ft_find_ret(trant->cmd_in)) != -1)
	{
		if ((cmd = ft_strndup(trant->cmd_in, offset)))
		{
			trant->current_cmd = ft_strdup(cmd);
			gettimeofday(&(trant->time), NULL);
			if (!ft_strcmp("incantation", cmd))
				sv_incantation(game, trant);
			trant->send = 1;
			sv_add_time(cmd, game, trant);
		}
		free(cmd);
		tmp = ft_strdup(trant->cmd_in + offset + 1);
		ft_bzero(trant->cmd_in, WORK_BUFSIZE);
		ft_strcat(trant->cmd_in, tmp);
		free(tmp);
	}
}
