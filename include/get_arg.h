/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 08:03:59 by bjacob            #+#    #+#             */
/*   Updated: 2014/06/11 13:46:49 by bjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_ARG_H
# define GET_ARG_H

# include "libft.h"

typedef struct	s_arg
{
	int			port;
	int			width;
	int			height;
	int			nbmax;
	int			t;
	t_list		*team;
}				t_arg;

char		*ft_under_space(char *s);

#endif
