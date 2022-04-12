/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 07:07:05 by aucousin          #+#    #+#             */
/*   Updated: 2022/01/04 07:15:23 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include"../hdrs/push_swap.h"

void	ft_ra(t_stacks *stacks)
{
	int	i;

	i = 0;
	while (i < stacks->sizea - 1)
	{
		ft_swap(&stacks->a[i], &stacks->a[i + 1]);
		i++;
	}
	printf("ra\n");
}

void	ft_rb(t_stacks *stacks)
{
	int	i;

	i = 0;
	while (i < stacks->sizeb - 1)
	{
		ft_swap(&stacks->b[i], &stacks->b[i + 1]);
		i++;
	}
	printf("rb\n");
}

void	ft_rr(t_stacks *stacks)
{
	ft_ra(stacks);
	ft_rb(stacks);
	printf("rr\n");
	return ;
}
