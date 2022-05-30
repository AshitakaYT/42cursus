/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 09:30:38 by acousin           #+#    #+#             */
/*   Updated: 2022/05/27 21:28:19 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/philosophers.h"

void	ft_exit(char *str)
{
	printf("%s\n", str);
}

unsigned int	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, 0) == -1)
		ft_exit("gettimeofday returned -1");
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	ft_usleep_improved(long time)
{
	long	actual;
	long	start;

	start = get_time();
	actual = get_time();
	while ((actual - start) < time)
	{
		usleep(250);
		actual = get_time();
	}
	return (1);
}

int	ft_usleep_improved2(long time)
{
	long	actual;
	long	start;

	start = get_time();
	actual = get_time();
	while (actual - start < time)
	{
		usleep(100);
		actual = get_time();
	}
	return (1);
}
