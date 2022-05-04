/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 07:09:20 by aucousin          #+#    #+#             */
/*   Updated: 2022/04/26 11:40:54 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/push_swap.h"

int	ft_parsing1(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	if (ac == 1)
		return (0);
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (j == 0 && (av[i][j] == '-' || av[i][j] == '+') && av[i][j + 1])
				j++;
			if (!ft_isdigit(av[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_parsing2(t_stacks *stacks)
{
	int	i;
	int	j;

	i = 0;
	j = i + 1;
	if (stacks->sizeinit < 1 || !stacks->a || !stacks->b || !stacks->alabeled)
		return (0);
	while (i < stacks->sizeinit)
	{
		j = i + 1;
		while (j < stacks->sizeinit)
		{
			if (stacks->a[j] == stacks->a[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_int(const char *str)
{
	int			i;
	int			sign;
	long int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == '\f' || str[i] == '\n' || str[i] == '\r'\
			|| str[i] == '\t' || str[i] == '\v' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		if (result >= 2147483647 || (result >= 2147483648 && sign == -1))
			return (0);
		i++;
	}
	return (1);
}

void	ft_get_args(t_stacks *stacks, int ac, char **av)
{
	int	i;

	i = 1;
	stacks->a = malloc(sizeof(int) * (ac - 1));
	if (!stacks->a)
		return ;
	while (i < ac)
	{
		if (!ft_check_int(av[i]))
		{
			stacks->a = NULL;
			free(stacks->a);
			return ;
		}
		stacks->a[i - 1] = ft_atoi(av[i]);
		i++;
	}
}
