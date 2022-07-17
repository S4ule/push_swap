/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalesme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:47:21 by sbalesme          #+#    #+#             */
/*   Updated: 2022/06/20 15:48:40 by sbalesme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	ft_result(int i)
{
	if (i == 2)
		ft_error("Error\n");
	else if (i == 1)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}

int	main(int ac, char **av)
{
	t_tab	*tab_a;
	t_tab	*tab_b;
	int		i;

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
		i = ft_slove(tab_a, tab_b);
		ft_result(i);
		free(tab_a);
		free(tab_b);
	}
	return (0);
}
