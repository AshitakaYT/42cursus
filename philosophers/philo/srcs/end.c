/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 10:01:19 by aucousin          #+#    #+#             */
/*   Updated: 2022/05/27 18:19:12 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/philosophers.h"

int	ft_is_dead(t_philo *philo)
{
	long	time;
	long	diff;

	time = get_time();
	pthread_mutex_lock(&philo->mealmutex);
	diff = time - philo->lastmeal;
	pthread_mutex_unlock(&philo->mealmutex);
	if (diff >= philo->banquet->die)
	{
		return (1);
	}
	return (0);
}

int	ft_are_dead(t_banquet *banquet)
{
	unsigned int	i;

	i = 0;
	while (i < banquet->seats)
	{
		if (ft_is_dead(&banquet->philos[i]))
		{
			pthread_mutex_lock(&banquet->death);
			banquet->isfinished = 1;
			pthread_mutex_unlock(&banquet->death);
			return (i + 1);
		}
		i++;
	}
	return (0);
}

int	ft_is_everyone_full(t_banquet *banquet)
{
	unsigned int	i;

	i = 0;
	while (i < banquet->seats)
	{
		pthread_mutex_lock(&banquet->philos[i].mealsmutex);
		if (banquet->philos[i].meals < banquet->diet)
		{
			pthread_mutex_unlock(&banquet->philos[i].mealsmutex);
			return (0);
		}
		pthread_mutex_unlock(&banquet->philos[i].mealsmutex);
		i++;
	}
	pthread_mutex_lock(&banquet->death);
	banquet->isfinished = 1;
	pthread_mutex_unlock(&banquet->death);
	return (1);
}

void	ft_destroy_philos(t_banquet *banquet)
{
	unsigned int	i;

	i = 0;
	while (i < banquet->seats)
	{
		pthread_mutex_destroy(&banquet->philos[i].lfork);
		pthread_mutex_destroy(&banquet->philos[i].mealmutex);
		i++;
	}
}

void	ft_destroy_banquet(t_banquet *banquet)
{
	pthread_mutex_destroy(&banquet->message);
	pthread_mutex_destroy(&banquet->death);
	ft_destroy_philos(banquet);
	free(banquet->philos);
}
