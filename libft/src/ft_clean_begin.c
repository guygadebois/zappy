/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_begin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/04 18:25:34 by glourdel          #+#    #+#             */
/*   Updated: 2013/12/04 18:50:41 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_clean_begin(char *s, char *allow)
{
	int		i;

	if (s)
	{
		while (*s)
		{
			i = 0;
			while (allow[i])
			{
				if (*s == allow[i])
					return (s);
				i++;
			}
			s++;
		}
	}
	return (s);
}
