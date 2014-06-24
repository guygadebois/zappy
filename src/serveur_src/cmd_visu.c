/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_visu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcouly <dcouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/09 17:47:05 by dcouly            #+#    #+#             */
/*   Updated: 2014/06/24 13:22:17 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "server.h"
#include "types.h"

static void		sv_check(char *cmd, t_data *game)
{
	int	time;

	if (!ft_strncmp("sst", cmd, 3))
	{
		time = ft_atoi(&cmd[4]);
		if (time > 0)
			game->time = time;
		ft_strcat(game->visu.cmd_out, "sgt ");
		ft_strcat(game->visu.cmd_out, ft_itoa(time));
		ft_strcat(game->visu.cmd_out, "\n");
	}
}

void			sv_cmd_visu(t_data *game, char *buf, int rd_oct)
{
	char	*tmp;
	char	*cmd;
	int		offset;

	ft_strncat(game->visu.cmd_in, buf, rd_oct);
	while ((offset = ft_find_ret(game->visu.cmd_in)) != -1)
	{
		if ((cmd = ft_strndup(game->visu.cmd_in, offset)))
			sv_check(cmd, game);
		free(cmd);
		tmp = ft_strdup(game->visu.cmd_in + offset + 1);
		ft_bzero(game->visu.cmd_in, WORK_BUFSIZE);
		ft_strcat(game->visu.cmd_in, tmp);
		free(tmp);
	}
}
