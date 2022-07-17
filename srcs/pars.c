/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalesme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:19:36 by sbalesme          #+#    #+#             */
/*   Updated: 2022/06/17 15:11:16 by sbalesme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

ssize_t	number_of_args(int ac, char **av)
{
	ssize_t	res;
	ssize_t	tmp;

	res = 0;
	while (--ac > 0)
	{
		tmp = check_string(av[ac]);
		if (tmp == -1)
			return (-1);
		res += tmp;
	}
	return (res);
}

long	ft_atoi(char *str)
{
	long	res;
	long	neg;

	neg = 1;
	while (*str && (*str == ' ' || *str == '\t'))
		str++;
	if (*str && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	res = 0;
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (res * neg);
}

void	ft_get_n(char *str, t_tab *tab_a, ssize_t *res)
{
	while (*str)
	{
		while (*str && (*str == ' ' || *str == '\t'))
			str++;
		if (*str)
		{
			if (check_atoi(str) == 1)
			{
				*res = -1;
				return ;
			}
			tab_a[*res].n = (int)ft_atoi(str);
			tab_a[*res].group = 0;
			(*res)++;
		}
		while (*str && *str != ' ' && *str != '\t')
			str++;
	}
}

int	ft_put_n_in_tab(t_tab *tab_a, char **av, int ac)
{
	ssize_t	i;
	int		save_ac;

	i = 1;
	save_ac = ac;
	while (--ac > 0)
	{
		ft_get_n(av[save_ac - ac], tab_a, &i);
		if (i == -1)
			return (1);
	}
	return (0);
}

int	ft_init_tabs(t_tab **tab_a, t_tab **tab_b, int ac, char **av)
{
	ssize_t	size;

	size = number_of_args(ac, av);
	if (size == -1)
		return (1);
	*tab_a = malloc(sizeof(t_tab) * (size + 1));
	*tab_b = malloc(sizeof(t_tab) * (size + 1));
	if (*tab_a == 0 || *tab_b == 0)
		return (1);
	if (ft_put_n_in_tab(*tab_a, av, ac) == 1)
		return (1);
	tab_a[0]->n = size;
	tab_b[0]->n = 0;
	tab_a[0]->group = -1;
	tab_b[0]->group = -1;
	if (check_doublon(*tab_a) == 1)
		return (1);
	return (0);
}
