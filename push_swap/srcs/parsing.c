/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 07:09:20 by aucousin          #+#    #+#             */
/*   Updated: 2022/04/12 16:21:19 by aucousin         ###   ########lyon.fr   */
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
			if (av[i][j] == '-' && av[i][j + 1])
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
	if (stacks->sizeinit < 1)
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
		if (result > 2147483647 || (result > 2147483648 && sign == -1))
			return (0);
		i++;
	}
	return (1);
}

int	*ft_get_args(int ac, char **av)
{
	int	i;
	int	*stacks;

	i = 1;
	stacks = malloc(sizeof(int) * (ac - 1));
	while (i < ac)
	{
		if (!ft_check_int(av[i]))
		{
			free(stacks);
			return (NULL);
		}
		stacks[i - 1] = ft_atoi(av[i]);
		i++;
	}
	return (stacks);
}
