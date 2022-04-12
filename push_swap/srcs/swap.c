/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 07:07:02 by aucousin          #+#    #+#             */
/*   Updated: 2022/01/04 07:01:13 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include"../hdrs/push_swap.h"

void	ft_swap(int *a, int *b)
{
	int		c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_sa(t_stacks *stacks)
{
	if (stacks->sizea >= 2)
	{
		ft_swap(&stacks->a[0], &stacks->a[1]);
		printf("sa\n");
	}
}

void	ft_sb(t_stacks *stacks)
{
	if (stacks->sizeb >= 2)
	{
		ft_swap(&stacks->b[0], &stacks->b[1]);
		printf("sb\n");
	}
}

void	ft_ss(t_stacks *stacks)
{
	if (stacks->sizea >= 2 && stacks->sizeb >= 2)
	{
		ft_swap(&stacks->a[0], &stacks->a[1]);
		ft_swap(&stacks->b[0], &stacks->b[1]);
		printf("ss\n");
	}
}
