/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_short.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalesme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:07:59 by sbalesme          #+#    #+#             */
/*   Updated: 2022/06/20 15:09:04 by sbalesme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_finish_this(t_tab *tab)
{
	if (tab[3].n < tab[1].n)
	{
		write(1, "rra\n", 4);
		r_rotate(tab);
	}
	else if (tab[3].n > tab[1].n && tab[2].n > tab[3].n)
	{
		write(1, "ra\n", 3);
		rotate(tab);
		write(1, "sa\n", 3);
		swap(tab);
		write(1, "rra\n", 4);
		r_rotate(tab);
	}
}

static void	ft_short_three(t_tab *tab)
{
	if (tab[1].n > tab[2].n)
	{
		if (tab[1].n > tab[3].n)
		{
			write(1, "ra\n", 3);
			rotate(tab);
			if (tab[1].n > tab[2].n)
			{
				write(1, "sa\n", 3);
				swap(tab);
			}
		}
		else
		{
			write(1, "sa\n", 3);
			swap(tab);
		}
	}
	ft_finish_this(tab);
}

static void	very_small_short(t_tab *tab)
{
	if (tab[0].n == 2)
	{
		if (tab[1].n > tab[2].n)
		{
			write(1, "sa\n", 3);
			swap(tab);
		}
	}
	else
		ft_short_three(tab);
}

void	small_short(t_tab *tab_a, t_tab *tab_b)
{
	int	i;

	while (tab_a[0].n > 3)
	{
		i = ft_find_min(tab_a);
		while (i > 0)
			ft_go_i(tab_a, &i, 1);
		write(1, "pb\n", 3);
		push_b(tab_a, tab_b);
	}
	very_small_short(tab_a);
	while (tab_b[0].n > 0)
	{
		write(1, "pa\n", 3);
		push_a(tab_a, tab_b);
	}
}
