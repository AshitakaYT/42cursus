/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 17:11:28 by aucousin          #+#    #+#             */
/*   Updated: 2022/04/12 16:23:17 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "hdrs/push_swap.h"

void	ft_label_a(t_stacks *stacks)
{
	int	i;
	int	j;

	i = 0;
	while (i < stacks->sizea)
	{
		j = 0;
		while (j < stacks->sizea)
		{
			if (stacks->alabeled[j] == stacks->a[i])
			{
				stacks->a[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	ft_solve_big(t_stacks *stacks)
{
	int	maxbits;
	int	i;
	int	j;

	i = 0;
	maxbits = 0;
	while (((stacks->sizeinit - 1) >> maxbits) != 0)
		maxbits++;
	while (i < maxbits)
	{
		j = 0;
		while (j < stacks->sizeinit)
		{
			if (((stacks->a[0] >> i) & 1) == 1)
				ft_ra(stacks);
			else
				ft_pb(stacks);
			j++;
		}
		while (j--)
		{
			ft_pa(stacks);
		}
		i++;
	}
}

void	ft_sort_big_stack(t_stacks *stacks)
{
	ft_copy_a(stacks);
	ft_sort_int_tab(stacks->alabeled, stacks->sizea);
	ft_label_a(stacks);
}

void	ft_push_swap(t_stacks *stacks)
{
	if (ft_is_sorted(stacks->a, stacks->sizea))
		return ;
	ft_sort_big_stack(stacks);
	if (stacks->sizea <= 5)
		ft_solve_small(stacks);
	else
	{
		ft_solve_big(stacks);
	}
}

int	main(int ac, char **av)
{
	t_stacks	stacks;

	if (!ft_parsing1(ac, av))
		return (0);
	ft_init(&stacks, ac, av);
	if (!ft_parsing2(&stacks))
	{
		free(stacks.a);
		free(stacks.b);
		free(stacks.alabeled);
		printf("unvalid parameters.\n");
		return (0);
	}
	else
	{
		ft_push_swap(&stacks);
		free(stacks.a);
		free(stacks.b);
		free(stacks.alabeled);
		return (0);
	}
}
