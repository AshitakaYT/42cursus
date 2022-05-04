/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 07:06:39 by aucousin          #+#    #+#             */
/*   Updated: 2022/04/15 11:07:02 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include"../hdrs/push_swap.h"

void	ft_pa(t_stacks *stacks)
{
	int	i;

	i = 0;
	if (stacks->sizeb != 0)
	{
		i = stacks->sizea;
		while (i > 0)
		{
			ft_swap(&stacks->a[i], &stacks->a[i - 1]);
			i--;
		}
		ft_swap(&stacks->a[i], &stacks->b[i]);
		stacks->sizeb--;
		stacks->sizea++;
		while (i < stacks->sizeb)
		{
			ft_swap(&stacks->b[i], &stacks->b[i + 1]);
			i++;
		}
		ft_putstr_fd("pa\n", 1);
	}
}

void	ft_pb(t_stacks *stacks)
{
	int	i;

	i = 0;
	if (stacks->sizea != 0)
	{
		i = stacks->sizeb;
		while (i > 0)
		{
			ft_swap(&stacks->b[i], &stacks->b[i - 1]);
			i--;
		}
		ft_swap(&stacks->b[i], &stacks->a[i]);
		stacks->sizea--;
		stacks->sizeb++;
		while (i < stacks->sizea)
		{
			ft_swap(&stacks->a[i], &stacks->a[i + 1]);
			i++;
		}
		ft_putstr_fd("pb\n", 1);
	}
}
