/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vision_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcouly <dcouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 15:33:02 by dcouly            #+#    #+#             */
/*   Updated: 2014/06/26 15:36:07 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "types.h"
#include "server.h"

char	*ft_strstrjoin(int nb, ...)
{
	va_list		ap;
	char		*str;
	char		*ptr;
	char		*tmp;

	va_start(ap, nb);
	ptr = ft_strnew(1);
	if (ptr == NULL || nb < 0)
		return (NULL);
	while (nb > 0)
	{
		str = ft_strdup(va_arg(ap, char *));
		tmp = ptr;
		ptr = ft_strjoin(tmp, str);
		free(str);
		free(tmp);
		nb--;
	}
	va_end(ap);
	return (ptr);
}
