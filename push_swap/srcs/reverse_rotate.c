/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 07:07:08 by aucousin          #+#    #+#             */
/*   Updated: 2022/04/15 11:07:14 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include"../hdrs/push_swap.h"

void	ft_rra(t_stacks *stacks)
{
	int	i;

	i = stacks->sizea - 1;
	while (i > 0)
	{
		ft_swap(&stacks->a[i], &stacks->a[i - 1]);
		i--;
	}
	ft_putstr_fd("rra\n", 1);
}

void	ft_rrb(t_stacks *stacks)
{
	int	i;

	i = stacks->sizeb - 1;
	while (i > 0)
	{
		ft_swap(&stacks->b[i], &stacks->b[i - 1]);
		i--;
	}
	ft_putstr_fd("rrb\n", 1);
}

void	ft_rrr(t_stacks *stacks)
{
	ft_rra(stacks);
	ft_rrb(stacks);
	ft_putstr_fd("rrr\n", 1);
}
