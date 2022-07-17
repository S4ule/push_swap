/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalesme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 13:20:09 by sbalesme          #+#    #+#             */
/*   Updated: 2022/06/20 15:42:04 by sbalesme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_short_b(t_tab *tab_a, t_tab *tab_b)
{
	int	i;

	while (tab_b[0].n != 0)
	{
		i = ft_look(tab_b, ft_find_min(tab_b), ft_find_max(tab_b));
		while (i > 0)
			ft_go_i(tab_b, &i, 2);
		if (ft_find_max(tab_b) == 0)
			i = 1;
		write(1, "pa\n", 3);
		push_a(tab_a, tab_b);
		if (i != 1)
		{
			write(1, "ra\n", 3);
			rotate(tab_a);
		}
	}
}

int	ft_find_group(t_tab *tab, int group)
{
	int	i;
	int	x;
	int	y;
	int	mid;

	if (tab[0].n == 0)
		return (-1);
	mid = ft_get_mid(tab[0].n);
	i = 1;
	x = 0;
	y = 0;
	while (i <= mid && tab[i].group != group)
		i++;
	if (tab[i].group == group)
		x = i;
	i = tab[0].n;
	while (i > mid && tab[i].group != group)
		i--;
	if (tab[i].group == group)
		y = i;
	return (ft_look(tab, x - 1, y - 1));
}

int	ft_find_start(t_tab *tab_a, t_tab *tab_b)
{
	int	i;
	int	max;
	int	res;

	max = tab_b[ft_find_max(tab_b) + 1].n;
	res = ft_find_max(tab_a) + 1;
	i = 1;
	while (i <= tab_a[0].n)
	{
		if (tab_a[i].n < tab_a[res].n && tab_a[i].n > max)
			res = i;
		i++;
	}
	return (res - 1);
}

void	ft_start(t_tab *tab_a, t_tab *tab_b)
{
	int	group;
	int	max_group;
	int	i;

	group = ft_get_group(tab_a, tab_b);
	max_group = group;
	while (group >= 0)
	{
		i = ft_find_group(tab_a, group);
		while (i >= 0)
		{
			while (i != 0)
				ft_go_i(tab_a, &i, 1);
			write(1, "pb\n", 3);
			push_b(tab_a, tab_b);
			i = ft_find_group(tab_a, group);
		}
		if (group < max_group)
			i = ft_find_start(tab_a, tab_b);
		while (i > 0)
			ft_go_i(tab_a, &i, 1);
		ft_short_b(tab_a, tab_b);
		group--;
	}
}

void	ft_short(t_tab *tab_a, t_tab *tab_b)
{
	int	i;

	if (tab_a[0].n <= 1)
		return ;
	if (look_if_sort(tab_a) == 0)
		return ;
	if (tab_a[0].n > 1 && tab_a[0].n < 6)
		small_short(tab_a, tab_b);
	if (look_if_sort(tab_a) != 0)
	{
		ft_start(tab_a, tab_b);
		i = ft_find_min(tab_a);
		while (i > 0)
			ft_go_i(tab_a, &i, 1);
	}
	return ;
}
