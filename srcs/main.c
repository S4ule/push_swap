/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalesme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:13:58 by sbalesme          #+#    #+#             */
/*   Updated: 2022/07/14 13:56:47 by sbalesme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_error(char *str)
{
	write(2, str, ft_strlen(str));
	return (1);
}

int	main(int ac, char **av)
{
	t_tab	*tab_a;
	t_tab	*tab_b;

	tab_a = 0;
	tab_b = 0;
	if (ac > 1)
	{
		if (ft_init_tabs(&tab_a, &tab_b, ac, av) == 1)
		{
			free(tab_a);
			free(tab_b);
			ft_error("Error\n");
			return (1);
		}
		ft_short(tab_a, tab_b);
		free(tab_a);
		free(tab_b);
	}
	return (0);
}
