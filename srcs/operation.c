/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalesme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 13:25:47 by sbalesme          #+#    #+#             */
/*   Updated: 2022/06/20 15:06:47 by sbalesme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//sa sb ss
void	swap(t_tab	*tab)
{
	t_tab	tmp;

	if (tab[0].n > 1)
	{
		tmp.n = tab[1].n;
		tmp.group = tab[1].group;
		tab[1].n = tab[2].n;
		tab[1].group = tab[2].group;
		tab[2].n = tmp.n;
		tab[2].group = tmp.group;
	}
	return ;
}

//pa pb
void	push_a(t_tab *tab_a, t_tab *tab_b)
{
	int	tmp;

	if (tab_b[0].n > 0)
	{
		tmp = tab_a[0].n;
		while (tmp >= 1)
		{
			tab_a[tmp + 1].n = tab_a[tmp].n;
			tab_a[tmp + 1].group = tab_a[tmp].group;
			tmp--;
		}
		tab_a[1].n = tab_b[1].n;
		tab_a[1].group = tab_b[1].group;
		tab_a[0].n += 1;
		tmp = 1;
		while (tmp < tab_b[0].n)
		{
			tab_b[tmp].n = tab_b[tmp + 1].n;
			tab_b[tmp].group = tab_b[tmp + 1].group;
			tmp++;
		}
		tab_b[0].n -= 1;
	}
	return ;
}

//pb
void	push_b(t_tab *tab_a, t_tab *tab_b)
{
	int	tmp;

	if (tab_a[0].n > 0)
	{
		tmp = tab_b[0].n;
		while (tmp >= 1)
		{
			tab_b[tmp + 1].n = tab_b[tmp].n;
			tab_b[tmp + 1].group = tab_b[tmp].group;
			tmp--;
		}
		tab_b[1].n = tab_a[1].n;
		tab_b[1].group = tab_a[1].group;
		tab_b[0].n += 1;
		tmp = 1;
		while (tmp < tab_a[0].n)
		{
			tab_a[tmp].n = tab_a[tmp + 1].n;
			tab_a[tmp].group = tab_a[tmp + 1].group;
			tmp++;
		}
		tab_a[0].n -= 1;
	}
	return ;
}

//ra rb rr
void	rotate(t_tab *tab)
{
	t_tab	tmp;
	int		i;

	i = 1;
	tmp.n = tab[1].n;
	tmp.group = tab[1].group;
	while (i < tab[0].n)
	{
		tab[i].n = tab[i + 1].n;
		tab[i].group = tab[i + 1].group;
		i++;
	}
	tab[tab[0].n].n = tmp.n;
	tab[tab[0].n].group = tmp.group;
	return ;
}

//rra rrb rrr
void	r_rotate(t_tab *tab)
{
	t_tab	tmp;
	int		i;

	i = tab[0].n;
	tmp.n = tab[tab[0].n].n;
	tmp.group = tab[tab[0].n].group;
	while (1 < i)
	{
		tab[i].n = tab[i - 1].n;
		tab[i].group = tab[i - 1].group;
		i--;
	}
	tab[1].n = tmp.n;
	tab[1].group = tmp.group;
	return ;
}
