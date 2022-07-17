/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalesme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:05:35 by sbalesme          #+#    #+#             */
/*   Updated: 2022/06/17 15:04:32 by sbalesme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_n(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str && *str >= '0' && *str <= '9')
		str++;
	if (*str && *str != ' ' && *str != '\t')
		return (1);
	return (0);
}

ssize_t	check_string(char *str)
{
	ssize_t	res;

	res = 0;
	while (*str)
	{
		while (*str && (*str == ' ' || *str == '\t'))
			str++;
		if (*str)
		{
			if (check_if_n(str) == 1)
				return (-1);
			res++;
		}
		while (*str && *str != ' ' && *str != '\t')
			str++;
	}
	return (res);
}

int	check_doublon(t_tab *tab)
{
	int	i;
	int	j;

	i = 1;
	while (i <= tab[0].n)
	{
		j = i + 1;
		while (j <= tab[0].n)
		{
			if (tab[i].n == tab[j].n)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_atoi(char *str)
{
	long	res;

	while (*str && (*str == ' ' || *str == '\t'))
		str++;
	if (*str && (*str == '+' || *str == '-'))
		str++;
	if (*str == 0 || *str < '0' || *str > '9')
		return (1);
	res = 0;
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		if ((int)res != (long)res)
			return (1);
		str++;
	}
	return (0);
}
