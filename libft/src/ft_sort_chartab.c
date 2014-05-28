/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_chartab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 15:45:27 by glourdel          #+#    #+#             */
/*   Updated: 2014/04/16 17:58:36 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_sort_chartab(char **tab, int (*f)(const char *, const char *))
{
	int		i;
	int		ret;
	char	*buf;

	ret = 1;
	while (ret)
	{
		i = 0;
		while (tab[i])
		{
			if (tab[i + 1] && (*f)(tab[i], tab[i + 1]) > 0)
			{
				buf = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = buf;
			}
			i++;
		}
		ret = 0;
	}
}
