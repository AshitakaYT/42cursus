/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 07:37:12 by aucousin          #+#    #+#             */
/*   Updated: 2022/04/12 16:03:19 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/push_swap.h"

void	ft_print_stacks(t_stacks stacks)
{
	int	i;

	i = 0;
	printf("A ------------ B ------------ labeled\n");
	while (stacks.sizeinit > i)
	{
		printf("%d - %d  %d\n", stacks.a[i], stacks.b[i], stacks.alabeled[i]);
		i++;
	}
	printf("\n\n\n");
}

int	ft_is_sorted(int *a, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i;
		while (j < size)
		{
			if (a[j] < a[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_sort_int_tab(int *tab, int size)
{
	int		i;
	int		j;
	int		swap;

	i = 0;
	while (i < size)
	{
		j = i;
		while (j < size)
		{
			if (tab[j] < tab[i])
			{
				swap = tab[j];
				tab[j] = tab[i];
				tab[i] = swap;
				j = i;
			}
			j++;
		}
		i++;
	}
}

void	ft_up_smaller(t_stacks *stacks)
{
	while (stacks->a[0] != 0 && stacks->a[0] != 1)
		ft_ra(stacks);
}
