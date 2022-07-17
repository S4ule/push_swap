/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalesme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:45:52 by sbalesme          #+#    #+#             */
/*   Updated: 2022/06/20 15:46:10 by sbalesme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include "get_next_line.h"

typedef struct s_tab
{
	int	n;
	int	group;
}		t_tab;

void	ft_print_tab(t_tab *tab, int t);
int		ft_init_tabs(t_tab **tab_a, t_tab **tab_b, int ac, char **av);
ssize_t	check_string(char *str);
int		check_doublon(t_tab *tab);
int		check_atoi(char *str);
int		swap(t_tab *tab);
int		push_a(t_tab *tab_a, t_tab *tab_b);
int		push_b(t_tab *tab_a, t_tab *tab_b);
int		rotate(t_tab *tab);
int		r_rotate(t_tab *tab);
int		ft_slove(t_tab *tab_a, t_tab *tab_b);

#endif
