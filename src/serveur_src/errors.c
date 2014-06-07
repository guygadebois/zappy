/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 18:27:06 by glourdel          #+#    #+#             */
/*   Updated: 2014/06/07 18:43:39 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			err_function(char *function)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd(function, 2);
	ft_putstr_fd("() failed...", 2);
	ft_putendl_fd(COLOR_END, 2);
	return (0);
}

int			err_malloc(void)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd("ERROR: malloc() failed...", 2);
	ft_putendl_fd(COLOR_END, 2);
	return (0);
}
