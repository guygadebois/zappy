/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 22:18:05 by glourdel          #+#    #+#             */
/*   Updated: 2014/04/23 16:40:56 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# define BUFF_SIZE 32

typedef struct	s_bufdata
{
	int		rd_oct;
	int		ret_pos;
	t_list	*list;
	t_list	*beg_ptr;
	char	*buf;
}				t_bufdata;

int				get_next_line(int const fd, char **line);

#endif
