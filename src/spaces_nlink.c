/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spaces_nlink.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 15:32:38 by ommadhi           #+#    #+#             */
/*   Updated: 2019/09/30 17:17:17 by ommadhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static char		*ft_strnews(size_t size)
{
	char		*str;
	size_t		i;

	i = 0;
	str = (char*)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	while (i < size)
	{
		str[i] = ' ';
		i++;
	}
	str[size] = '\0';
	return (str);
}

static int		get_max_lent(t_node *dr)
{
	int			max;
	int			lent;

	max = 0;
	while (dr->next)
	{
		lent = ft_strlen(dr->nlink);
		if (lent >= max)
			max = lent;
		dr = dr->next;
	}
	return (max);
}

int				spaces_nlink(t_node **dr)
{
	t_node		*ptr;
	char		*ps;
	int			max;
	char		*space;

	ptr = *dr;
	max = get_max_lent(ptr);
	while (ptr->next)
	{
		space = ft_strnews(max - ft_strlen(ptr->nlink));
		ps = ft_strjoin(space, ptr->nlink);
		free(ptr->nlink);
		free(space);
		ptr->nlink = ft_strdup(ps);
		free(ps);
		ptr = ptr->next;
	}
	return (0);
}
