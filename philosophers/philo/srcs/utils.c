/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 13:39:23 by acousin           #+#    #+#             */
/*   Updated: 2022/05/27 19:10:01 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/philosophers.h"

static int	ft_result(long int n)
{
	if (n >= 0)
		return (-1);
	return (0);
}

int	ft_atoi(char const *str)
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
		if (result > 2147483648)
			return (ft_result(result * sign));
		i++;
	}
	return (result * sign);
}

int	ft_isdigit(int c)
{
	if (c > '9' || c < '0')
		return (0);
	return (1);
}

void	ft_onephilo(t_banquet *banquet)
{
	ft_message(banquet, THINK, 0);
	ft_message(banquet, FORK, 0);
	ft_usleep_improved2(banquet->die);
	ft_message(banquet, DEATH, 0);
}
