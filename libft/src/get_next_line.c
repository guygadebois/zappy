/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 22:15:09 by glourdel          #+#    #+#             */
/*   Updated: 2014/01/22 17:08:59 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"
#include "libft.h"

static int		merge_list(t_bufdata *data, char **line, int read_line_ret)
{
	size_t	len;

	len = 0;
	data->beg_ptr = data->list;
	while (data->beg_ptr)
	{
		len += data->beg_ptr->content_size;
		data->beg_ptr = data->beg_ptr->next;
	}
	if ((*line = ft_strnew(len)))
	{
		data->beg_ptr = data->list;
		while (data->beg_ptr)
		{
			*line = ft_strcat(*line, (char *)data->beg_ptr->content);
			data->beg_ptr = data->beg_ptr->next;
		}
		ft_lstclear(&data->list);
		ft_strdel(&data->buf);
		return (!(read_line_ret == 0 && len == 0));
	}
	ft_lstclear(&data->list);
	ft_strdel(&data->buf);
	return (-1);
}

static size_t	return_in_str(char *str)
{
	size_t	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			if (str[i] == '\n')
				return (i);
			i++;
		}
	}
	return (-1);
}

static int		insert_in_list(t_list **list, char *src, size_t len)
{
	char	*dest;

	if (!(dest = ft_strnew(len)))
		return (-1);
	ft_strlcat(dest, src, len + 1);
	dest[len] = '\0';
	ft_lstpushback(list, (void *)dest, len);
	return (1);
}

static int		read_line(int fd, t_bufdata *data, char *rest)
{
	size_t	strlcat_len;
	int		line_read;

	line_read = 0;
	while ((data->rd_oct = read(fd, data->buf, BUFF_SIZE)) > 0)
	{
		line_read = 1;
		data->buf[data->rd_oct] = '\0';
		if ((data->ret_pos = return_in_str(data->buf)) == -1)
		{
			if (insert_in_list(&data->list, data->buf, BUFF_SIZE) == -1)
				return (-1);
		}
		else
		{
			strlcat_len = BUFF_SIZE - data->ret_pos + 1;
			ft_strlcat(rest, data->buf + data->ret_pos + 1, strlcat_len);
			return (insert_in_list(&data->list, data->buf, data->ret_pos));
		}
	}
	return (line_read);
}

int				get_next_line(int const fd, char **line)
{
	static char	rest[BUFF_SIZE + 1] = {0};
	t_bufdata	data;
	int			read_line_ret;

	if (!(data.buf = ft_strnew(BUFF_SIZE)) || fd < 0)
		return (-1);
	data.list = NULL;
	if (rest[0])
	{
		if ((data.ret_pos = return_in_str(rest)) == -1)
		{
			insert_in_list(&data.list, rest, ft_strlen(rest));
			rest[0] = '\0';
		}
		else
		{
			insert_in_list(&data.list, rest, data.ret_pos);
			ft_memmove(rest, rest + data.ret_pos + 1, BUFF_SIZE - data.ret_pos);
			return (merge_list(&data, line, 1));
		}
	}
	read_line_ret = read_line(fd, &data, rest);
	data.ret_pos = 0;
	return (merge_list(&data, line, read_line_ret));
}
