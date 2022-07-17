/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalesme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:50:48 by sbalesme          #+#    #+#             */
/*   Updated: 2022/06/20 15:52:12 by sbalesme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

int	ft_strcnp(char *s1, char *s2)
{
	if (*s1 == '\n')
		return (-1);
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 == '\n')
		return (0);
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	ft_do_bis(char *str, t_tab *tab_a, t_tab *tab_b)
{
	if (ft_strcnp(str, "ra") == 0)
		return (rotate(tab_a));
	if (ft_strcnp(str, "rb") == 0)
		return (rotate(tab_b));
	if (ft_strcnp(str, "rr") == 0)
	{
		rotate(tab_a);
		return (rotate(tab_b));
	}
	if (ft_strcnp(str, "rra") == 0)
		return (r_rotate(tab_a));
	if (ft_strcnp(str, "rrb") == 0)
		return (r_rotate(tab_b));
	if (ft_strcnp(str, "rrr") == 0)
	{
		r_rotate(tab_a);
		return (r_rotate(tab_b));
	}
	return (-1);
}

int	ft_do(char *str, t_tab *tab_a, t_tab *tab_b)
{
	if (ft_strcnp(str, "sa") == 0)
		return (swap(tab_a));
	if (ft_strcnp(str, "sb") == 0)
		return (swap(tab_b));
	if (ft_strcnp(str, "ss") == 0)
	{
		swap(tab_a);
		return (swap(tab_b));
	}
	if (ft_strcnp(str, "pa") == 0)
		return (push_a(tab_a, tab_b));
	if (ft_strcnp(str, "pb") == 0)
		return (push_b(tab_a, tab_b));
	return (ft_do_bis(str, tab_a, tab_b));
}

int	ft_slove(t_tab *tab_a, t_tab *tab_b)
{
	char	*line;
	int		i;

	while (1)
	{
		line = get_next_line(0);
		if (line == 0)
			break ;
		i = ft_do(line, tab_a, tab_b);
		free(line);
		if (i != 0)
			return (2);
	}
	if (look_if_sort(tab_a) == 0 && tab_b[0].n == 0)
		return (0);
	return (1);
}
