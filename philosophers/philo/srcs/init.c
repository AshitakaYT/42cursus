/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 13:37:23 by acousin           #+#    #+#             */
/*   Updated: 2022/05/26 23:36:46 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/philosophers.h"

int	ft_zero(char **av)
{
	int	i;

	i = 1;
	while (i < 5)
	{
		if (!ft_atoi(av[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_parsing_chars(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_init_philos(t_banquet *banquet)
{
	unsigned int	i;

	i = 0;
	while (i < banquet->seats)
	{
		banquet->philos[i].position = i;
		banquet->philos[i].lastmeal = get_time();
		banquet->philos[i].banquet = banquet;
		banquet->philos[i].meals = 0;
		pthread_mutex_init(&banquet->philos[i].lfork, NULL);
		pthread_mutex_init(&banquet->philos[i].mealmutex, NULL);
		pthread_mutex_init(&banquet->philos[i].mealsmutex, NULL);
		i++;
	}
	if (i != 1)
	{
		i = 0;
		while (i < banquet->seats)
		{
			banquet->philos[i].rfork = &banquet->philos[i + 1].lfork;
			i++;
		}
		banquet->philos[i - 1].rfork = &banquet->philos[0].lfork;
	}
}

void	ft_init_banquet(t_banquet *banquet, int ac, char **av)
{
	int	i;

	i = 0;
	banquet->seats = ft_atoi(av[1]);
	banquet->die = ft_atoi(av[2]);
	banquet->eat = ft_atoi(av[3]);
	banquet->sleep = ft_atoi(av[4]);
	banquet->time_start = 0;
	banquet->isbegin = 0;
	banquet->isfinished = 0;
	pthread_mutex_init(&banquet->message, NULL);
	pthread_mutex_init(&banquet->death, NULL);
	if (ac == 6)
		banquet->diet = ft_atoi(av[5]);
	else
		banquet->diet = 0;
	banquet->philos = malloc(sizeof(t_philo) * banquet->seats);
	if (!banquet->philos)
		return ;
	ft_init_philos(banquet);
}
