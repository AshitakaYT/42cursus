/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_small.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:04:53 by aucousin          #+#    #+#             */
/*   Updated: 2022/04/13 09:00:41 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/push_swap.h"

void	ft_two(t_stacks *stacks)
{
	if (stacks->a[0] < stacks->a[1])
		ft_ra(stacks);
}

void	ft_three(t_stacks *stacks)
{
	if (ft_is_sorted(stacks->a, stacks->sizea))
		return ;
	if (stacks->a[2] > stacks->a[0] && stacks->a[0] > stacks->a[1])
		ft_sa(stacks);
	else if (stacks->a[0] > stacks->a[1] && stacks->a[1] > stacks->a[2])
	{
		ft_sa(stacks);
		ft_rra(stacks);
	}
	else if (stacks->a[0] > stacks->a[2] && stacks->a[1] < stacks->a[2])
		ft_ra(stacks);
	else if (stacks->a[0] < stacks->a[1] && stacks->a[0] > stacks->a[2])
		ft_rra(stacks);
	else
	{
		ft_sa(stacks);
		ft_ra(stacks);
	}
}

void	ft_four(t_stacks *stacks)
{
	while (stacks->a[0] != 0)
		ft_ra(stacks);
	ft_pb(stacks);
	ft_three(stacks);
	ft_pa(stacks);
}

void	ft_five(t_stacks *stacks)
{
	ft_up_smaller(stacks);
	ft_pb(stacks);
	ft_up_smaller(stacks);
	ft_pb(stacks);
	ft_three(stacks);
	if (stacks->b[0] < stacks->b[1])
		ft_sb(stacks);
	ft_pa(stacks);
	ft_pa(stacks);
}

void	ft_solve_small(t_stacks *stacks)
{
	if (stacks->sizeinit == 3)
		ft_three(stacks);
	else if (stacks->sizeinit == 2)
		ft_two(stacks);
	else if (stacks->sizeinit == 4)
		ft_four(stacks);
	else
		ft_five(stacks);
}
