/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 17:12:09 by aucousin          #+#    #+#             */
/*   Updated: 2022/04/12 16:03:06 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// INCLUDES

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

// STACKS STRUCT FOR CONVENIANCE

typedef struct s_stacks {
	int	*a;
	int	*b;
	int	*alabeled;
	int	sizea;
	int	sizeb;
	int	sizeinit;
}	t_stacks;

// MANDATORY FCTS

void	ft_pa(t_stacks *stacks);
void	ft_pb(t_stacks *stacks);
void	ft_rra(t_stacks *stacks);
void	ft_rrb(t_stacks *stacks);
void	ft_rrr(t_stacks *stacks);
void	ft_ra(t_stacks *stacks);
void	ft_rb(t_stacks *stacks);
void	ft_rr(t_stacks *stacks);
void	ft_swap(int *a, int *b);
void	ft_sa(t_stacks *stacks);
void	ft_sb(t_stacks *stacks);
void	ft_ss(t_stacks *stacks);

// ALGO

void	ft_solve_small(t_stacks *stacks);

// UTILS

void	ft_print_stacks(t_stacks stacks);
int		ft_is_sorted(int *a, int size);
void	ft_sort_int_tab(int *tab, int size);
void	ft_up_smaller(t_stacks *stacks);

// INIT

void	ft_init_b(t_stacks *stacks);
void	ft_init(t_stacks *stacks, int ac, char **av);
void	ft_copy_a(t_stacks *stacks);

// PARSING
int		ft_parsing1(int ac, char **av);
int		ft_parsing2(t_stacks *stacks);
int		*ft_get_args(int ac, char **av);

#endif