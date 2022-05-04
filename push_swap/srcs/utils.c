/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 07:37:12 by aucousin          #+#    #+#             */
/*   Updated: 2022/04/26 11:45:27 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/push_swap.h"

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

void	ft_free_stacks(t_stacks *stacks)
{
	if (stacks->a)
		free(stacks->a);
	if (stacks->b)
		free(stacks->b);
	if (stacks->alabeled)
		free(stacks->alabeled);
}
