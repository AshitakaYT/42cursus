/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 07:53:47 by aucousin          #+#    #+#             */
/*   Updated: 2022/04/12 16:03:27 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/push_swap.h"

void	ft_copy_a(t_stacks *stacks)
{
	int	i;

	i = 0;
	while (i < stacks->sizea)
	{
		stacks->alabeled[i] = stacks->a[i];
		i++;
	}
}

void	ft_init_b(t_stacks *stacks)
{
	int	i;

	i = 0;
	while (i < stacks->sizeinit)
	{
		stacks->b[i] = 0;
		stacks->alabeled[i] = 0;
		i++;
	}
}

void	ft_init(t_stacks *stacks, int ac, char **av)
{
	stacks->a = ft_get_args(ac, av);
	if (!stacks->a)
		return ;
	stacks->b = malloc(sizeof(int) * ac - 1);
	if (!stacks->b)
	{
		free(stacks->a);
		return ;
	}
	stacks->alabeled = malloc(sizeof(int) * ac - 1);
	if (!stacks->alabeled)
	{
		free(stacks->a);
		free(stacks->b);
		return ;
	}
	stacks->sizea = ac - 1;
	stacks->sizeb = 0;
	stacks->sizeinit = ac - 1;
	ft_init_b(stacks);
}
