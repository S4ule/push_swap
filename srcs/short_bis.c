/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalesme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:13:10 by sbalesme          #+#    #+#             */
/*   Updated: 2022/06/20 15:16:09 by sbalesme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	look_if_sort(t_tab *tab)
{
	int	i;
	int	j;

	i = 1;
	while (i < tab[0].n)
	{
		j = i + 1;
		while (j <= tab[0].n)
		{
			if (tab[i].n > tab[j].n)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_find_min(t_tab *tab)
{
	int	i;
	int	min;

	i = 1;
	min = i;
	while (i <= tab[0].n)
	{
		if (tab[i].n < tab[min].n)
			min = i;
		i++;
	}
	return (min - 1);
}

int	ft_find_max(t_tab *tab)
{
	int	i;
	int	max;

	i = 1;
	max = i;
	while (i <= tab[0].n)
	{
		if (tab[i].n > tab[max].n)
			max = i;
		i++;
	}
	return (max - 1);
}

int	ft_range(int i, int max)
{
	int	res;
	int	mid;

	if (max % 2 != 0)
		mid = (max + 1) / 2;
	else
		mid = (max / 2) + 1;
	res = 0;
	while (i != 0)
	{
		if (i < mid)
			i--;
		else
			i++;
		if (i > max)
			i = 0;
		res++;
	}
	return (res);
}

int	ft_look(t_tab *tab, int x, int y)
{
	int	step_x;
	int	step_y;

	if (x == -1 && y == -1)
		return (-1);
	else if (x == -1)
		return (y);
	else if (y == -1)
		return (x);
	step_x = ft_range(x, tab[0].n);
	step_y = ft_range(y, tab[0].n);
	if (step_x < step_y)
		return (x);
	else
		return (y);
}
