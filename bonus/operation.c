/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalesme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 13:25:47 by sbalesme          #+#    #+#             */
/*   Updated: 2022/06/17 15:02:55 by sbalesme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

//sa sb ss
int	swap(t_tab	*tab)
{
	int	tmp;

	if (tab[0].n > 1)
	{
		tmp = tab[1].n;
		tab[1].n = tab[2].n;
		tab[2].n = tmp;
	}
	return (0);
}

//pa pb
int	push_a(t_tab *tab_a, t_tab *tab_b)
{
	int	tmp;

	if (tab_b[0].n > 0)
	{
		tmp = tab_a[0].n;
		while (tmp >= 1)
		{
			tab_a[tmp + 1].n = tab_a[tmp].n;
			tmp--;
		}
		tab_a[1].n = tab_b[1].n;
		tab_a[0].n += 1;
		tmp = 1;
		while (tmp < tab_b[0].n)
		{
			tab_b[tmp].n = tab_b[tmp + 1].n;
			tmp++;
		}
		tab_b[0].n -= 1;
	}
	return (0);
}

//pb
int	push_b(t_tab *tab_a, t_tab *tab_b)
{
	int	tmp;

	if (tab_a[0].n > 0)
	{
		tmp = tab_b[0].n;
		while (tmp >= 1)
		{
			tab_b[tmp + 1].n = tab_b[tmp].n;
			tmp--;
		}
		tab_b[1].n = tab_a[1].n;
		tab_b[0].n += 1;
		tmp = 1;
		while (tmp < tab_a[0].n)
		{
			tab_a[tmp].n = tab_a[tmp + 1].n;
			tmp++;
		}
		tab_a[0].n -= 1;
	}
	return (0);
}

//ra rb rr
int	rotate(t_tab *tab)
{
	int	tmp;
	int	i;

	i = 1;
	tmp = tab[1].n;
	while (i < tab[0].n)
	{
		tab[i].n = tab[i + 1].n;
		i++;
	}
	tab[tab[0].n].n = tmp;
	return (0);
}

//rra rrb rrr
int	r_rotate(t_tab *tab)
{
	int	tmp;
	int	i;

	i = tab[0].n;
	tmp = tab[tab[0].n].n;
	while (1 < i)
	{
		tab[i].n = tab[i - 1].n;
		i--;
	}
	tab[1].n = tmp;
	return (0);
}
