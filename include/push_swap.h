/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalesme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:15:54 by sbalesme          #+#    #+#             */
/*   Updated: 2022/06/20 15:46:54 by sbalesme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_tab
{
	int	n;
	int	group;
}		t_tab;

void	ft_print_tab(t_tab *tab, int t);

//main.c -----

size_t	ft_strlen(char *str);

//pars.c -----

int		ft_init_tabs(t_tab **tab_a, t_tab **tab_b, int ac, char **av);

//pars_check.c -----

ssize_t	check_string(char *str);

int		check_doublon(t_tab *tab);

int		check_atoi(char *str);

//operation.c -----

//sa sb ss
void	swap(t_tab *tab);

//pa
void	push_a(t_tab *tab_a, t_tab *tab_b);

//pb
void	push_b(t_tab *tab_a, t_tab *tab_b);

//ra rb rr
void	rotate(t_tab *tab);

//rra rrb rrr
void	r_rotate(t_tab *tab);

//short

void	ft_short(t_tab *tab_a, t_tab *tab_b);

void	small_short(t_tab *tab_a, t_tab *tab_b);

//short_bis

int		look_if_sort(t_tab *tab);

int		ft_find_min(t_tab *tab);

int		ft_find_max(t_tab *tab);

int		ft_range(int i, int max);

int		ft_look(t_tab *tab, int x, int y);

//short_utils

int		ft_get_mid(int n);

void	ft_go_i(t_tab *tab, int *i, int mode);

int		ft_get_group(t_tab *tab_a, t_tab *tab_b);

#endif
