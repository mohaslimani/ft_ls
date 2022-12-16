/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:14:33 by ommadhi           #+#    #+#             */
/*   Updated: 2019/10/20 19:08:46 by ommadhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void				ft_rev_args(char **tab)
{
	int				i;
	int				j;
	char			*tmp;

	i = 0;
	j = 0;
	while (tab[j])
		j++;
	j--;
	while (i <= j)
	{
		tmp = tab[j];
		tab[j] = tab[i];
		tab[i] = tmp;
		i++;
		j--;
	}
}

void				ft_sort_time_args(char **tab)
{
	char			*can;
	int				ij[2];
	struct stat		data1;
	struct stat		data2;
	unsigned int	time[2];

	ij[1] = -1;
	while (tab[++ij[1]] != NULL)
	{
		ij[0] = 0;
		while (tab[ij[0]] && tab[ij[0] + 1])
		{
			lstat(tab[ij[0]], &data1);
			lstat(tab[ij[0] + 1], &data2);
			time[0] = data1.st_mtime;
			time[1] = data2.st_mtime;
			if (time[0] < time[1])
			{
				can = tab[ij[0]];
				tab[ij[0]] = tab[ij[0] + 1];
				tab[ij[0] + 1] = can;
			}
			ij[0]++;
		}
	}
}
