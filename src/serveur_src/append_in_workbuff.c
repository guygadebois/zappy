/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_in_workbuff.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcouly <dcouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 18:51:09 by dcouly            #+#    #+#             */
/*   Updated: 2014/06/07 19:10:42 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "server.h"
#include "types.h"

void	append_in_workbuf(t_data *game, t_trant *trant, char *buf, int rd_oct)
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
			printf("ok %d\n", game->sock);//	sv_treat_cmd(data, cmd, trant->sock);
			ft_strcpy(trant->cmd_out, "ok\n");
		}
		ft_strcpy(trant->cmd_out, "ok\n");
		free(cmd);
		tmp = ft_strdup(trant->cmd_in + offset + 1);
		ft_bzero(trant->cmd_in, WORK_BUFSIZE);
		ft_strcat(trant->cmd_in, tmp);
		free(tmp);
	}
}
