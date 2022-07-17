/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalesme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:40:43 by sbalesme          #+#    #+#             */
/*   Updated: 2022/06/20 15:43:16 by sbalesme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_mid(int n)
{
	int	res;

	if (n % 2 != 0)
		res = (n + 1) / 2;
	else
		res = (n / 2) + 1;
	return (res);
}

void	ft_go_i(t_tab *tab, int *i, int mode)
{
	int	mid;

	mid = ft_get_mid(tab[0].n);
	if (*i < mid)
	{
		if (mode == 1)
			write(1, "ra\n", 3);
		else if (mode == 2)
			write(1, "rb\n", 3);
		rotate(tab);
		(*i)--;
	}
	else if (*i != 0)
	{
		if (mode == 1)
			write(1, "rra\n", 4);
		else if (mode == 2)
			write(1, "rrb\n", 4);
		r_rotate(tab);
		(*i)++;
	}
	if (*i >= tab[0].n)
		*i = 0;
}

void	ft_creat_short_bis(t_tab *tab_a, t_tab *tab_b)
{
	int	i;
	int	j;

	i = 0;
	while (++i <= tab_a[0].n)
		tab_b[i] = tab_a[i];
	i = 1;
	while (i < tab_a[0].n)
	{
		j = i + 1;
		while (j <= tab_a[0].n)
		{
			if (tab_b[i].n > tab_b[j].n)
			{
				tab_b[i].n ^= tab_b[j].n;
				tab_b[j].n ^= tab_b[i].n;
				tab_b[i].n ^= tab_b[j].n;
			}
			j++;
		}
		i++;
	}
}

void	ft_init_group(t_tab *tab_a, t_tab *tab_b, int *group)
{
	int	i;
	int	j;
	int	size;

	i = 1;
	j = 0;
	*group = 0;
	if (tab_a[0].n >= 8)
		size = tab_a[0].n / 4;
	else
		size = 20;
	while (i <= tab_a[0].n)
	{
		if (j >= size)
		{
			(*group)++;
			j = 0;
		}
		tab_b[i].group = *group;
		i++;
		j++;
	}
}

int	ft_get_group(t_tab *tab_a, t_tab *tab_b)
{
	int	i;
	int	j;
	int	group;

	ft_creat_short_bis(tab_a, tab_b);
	ft_init_group(tab_a, tab_b, &group);
	i = 1;
	while (i <= tab_a[0].n)
	{
		j = 0;
		while (j <= tab_a[0].n)
		{
			if (tab_a[i].n == tab_b[j].n)
				tab_a[i].group = tab_b[j].group;
			j++;
		}
		i++;
	}
	return (group);
}
