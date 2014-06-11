/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_visu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcouly <dcouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/09 17:47:05 by dcouly            #+#    #+#             */
/*   Updated: 2014/06/11 13:19:12 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "server.h"
#include "types.h"

void	sv_cmd_visu(t_data *game, char *buf, int rd_oct)
{
	char	*tmp;
	char	*cmd;
	int		offset;

	ft_strncat(game->visu.cmd_in, buf, rd_oct);
	while ((offset = ft_find_ret(game->visu.cmd_in)) != -1)
	{
		if ((cmd = ft_strndup(game->visu.cmd_in, offset)))
		{
			printf("ok visu %d\n", game->visu.sock);//	sv_treat_cmd(data, cmd, trant->sock);
			ft_strcpy(game->visu.cmd_out, "visu\n");
		}
		ft_strcpy(game->visu.cmd_out, "ok\n");
		free(cmd);
		tmp = ft_strdup(game->visu.cmd_in + offset + 1);
		ft_bzero(game->visu.cmd_in, WORK_BUFSIZE);
		ft_strcat(game->visu.cmd_in, tmp);
		free(tmp);
	}
}
