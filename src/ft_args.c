/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 17:13:00 by ommadhi           #+#    #+#             */
/*   Updated: 2019/10/20 18:52:34 by ommadhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void				ft_check(char **tab)
{
	struct stat		data;
	int				i;

	i = 0;
	while (tab[i])
	{
		if (lstat(tab[i], &data) < 0)
			ft_put4str("ft_ls: ", tab[i], ": No such file or directory", "\n");
		i++;
	}
}

void				ft_sortargs(char **tab)
{
	char			*can;
	int				i;
	int				j;
	int				swapped;

	j = 0;
	while (tab[j] != NULL)
	{
		i = 0;
		swapped = 0;
		while (tab[i] && tab[i + 1])
		{
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
			{
				swapped = 1;
				can = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = can;
			}
			i++;
		}
		j++;
		if (swapped == 0)
			break ;
	}
}

void				sort_dir(char **tab, char **av, int option)
{
	int				i;
	int				j;
	struct stat		data;

	i = 0;
	j = 0;
	while (av[i])
	{
		if ((lstat(av[i], &data) != -1) && (data.st_mode & S_IFDIR))
		{
			tab[j] = ft_strdup(av[i]);
			j++;
		}
		i++;
	}
	tab[j] = NULL;
	(option & F) ? 0 : ft_sortargs(tab);
	(option & T && (!(option & F))) ? ft_sort_time_args(tab) : 0;
	(option & V && (!(option & F))) ? ft_rev_args(tab) : 0;
}

char				**tab_store(int size, char **av, int option)
{
	int				i;
	int				j;
	char			**tab;
	struct stat		data;

	tab = (char **)malloc(sizeof(char *) * (size + 1));
	i = 0;
	j = 0;
	while (av[i])
	{
		if ((lstat(av[i], &data) == -1) || !(data.st_mode & S_IFDIR))
		{
			tab[j] = ft_strdup(av[i]);
			j++;
		}
		i++;
	}
	tab[j] = NULL;
	(option & F) ? 0 : ft_sortargs(tab);
	ft_check(tab);
	(option & T && (!(option & F))) ? ft_sort_time_args(tab) : 0;
	(option & V && (!(option & F))) ? ft_rev_args(tab) : 0;
	sort_dir(&tab[j], av, option);
	return (tab);
}

char				**tab_args(int ac, char **av, int option)
{
	char			**tab;
	int				i;
	int				j;
	int				size;

	i = 0;
	j = 1;
	while ((av[j] && av[j][0] == '-' && av[j][1] != '\0'))
		j++;
	if (ac == j)
	{
		tab = (char **)malloc(sizeof(char *) * 2);
		tab[0] = ft_strdup(".");
		tab[1] = NULL;
		return (tab);
	}
	size = ac - j;
	tab = tab_store(size, &av[j], option);
	return (tab);
}
