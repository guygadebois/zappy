/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_types.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/16 14:39:32 by glourdel          #+#    #+#             */
/*   Updated: 2014/04/23 16:40:04 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_TYPES_H
# define LIBFT_TYPES_H

typedef unsigned int	t_uint;

typedef enum			e_bool
{
	TRUE = 1,
	FALSE = 0
}						t_bool;

typedef struct			s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}						t_list;

typedef struct			s_dlist
{
	void			*content;
	size_t			content_size;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}						t_dlist;

typedef struct			s_opt
{
	char			*options;
	size_t			len;
	size_t			min_len;
	size_t			prec;
}						t_opt;

typedef struct			s_flag
{
	char			*flag;
	size_t			(*f)(va_list *ap, t_opt *opt);
}						t_flag;

#endif
