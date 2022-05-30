/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:16:35 by aucousin          #+#    #+#             */
/*   Updated: 2022/05/27 21:11:20 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/philosophers.h"

void	ft_lock(t_banquet *banquet)
{
	pthread_mutex_lock(&banquet->message);
	pthread_mutex_lock(&banquet->death);
}

int	ft_message(t_banquet *banquet, int action, int id)
{
	unsigned int	time;

	ft_lock(banquet);
	if (banquet->isfinished == 1 && action != DEATH && action != FULL)
	{
		pthread_mutex_unlock(&banquet->death);
		pthread_mutex_unlock(&banquet->message);
		return (-1);
	}
	pthread_mutex_unlock(&banquet->death);
	time = get_time() - banquet->time_start;
	if (action == FORK)
		printf("%u %d has taken a fork\n", time, id + 1);
	else if (action == EAT)
		printf("\033[0;31m%u %d is eating\n\033[0m", time, id + 1);
	else if (action == THINK)
		printf("\033[0;32m%u %d is thinking\n\033[0m", time, id + 1);
	else if (action == SLEEP)
		printf("\033[0;34m%u %d is sleeping\n\033[0m", time, id + 1);
	else if (action == DEATH)
		printf("%u %d died\n", time, id);
	else if (action == FULL)
		printf("%u Each philosopher ate %d time(s)\n", time, banquet->diet);
	pthread_mutex_unlock(&banquet->message);
	return (1);
}

int	ft_take_forks2(t_philo *platon)
{
	pthread_mutex_lock(&platon->mealmutex);
	platon->lastmeal = get_time();
	pthread_mutex_unlock(&platon->mealmutex);
	if (ft_message(platon->banquet, EAT, platon->position) == -1)
	{
		pthread_mutex_unlock(&platon->lfork);
		pthread_mutex_unlock(platon->rfork);
		return (-1);
	}
	if (ft_usleep_improved(platon->banquet->eat) == -1)
	{
		pthread_mutex_unlock(&platon->lfork);
		pthread_mutex_unlock(platon->rfork);
		return (-1);
	}
	pthread_mutex_lock(&platon->mealsmutex);
	platon->meals++;
	pthread_mutex_unlock(&platon->mealsmutex);
	pthread_mutex_unlock(platon->rfork);
	pthread_mutex_unlock(&platon->lfork);
	if (ft_message(platon->banquet, SLEEP, platon->position) == -1)
		return (-1);
	if (ft_usleep_improved(platon->banquet->sleep) == -1)
		return (-1);
	return (1);
}

int	ft_take_forks(t_philo *platon)
{
	if (ft_message(platon->banquet, THINK, platon->position) == -1)
	{
		return (-1);
	}
	pthread_mutex_lock(&platon->lfork);
	if (ft_message(platon->banquet, FORK, platon->position) == -1)
	{
		pthread_mutex_unlock(&platon->lfork);
		return (-1);
	}
	pthread_mutex_lock(platon->rfork);
	if (ft_message(platon->banquet, FORK, platon->position) == -1)
	{
		pthread_mutex_unlock(&platon->lfork);
		pthread_mutex_unlock(platon->rfork);
		return (-1);
	}
	if (ft_take_forks2(platon) == -1)
		return (-1);
	return (1);
}
