/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 11:36:44 by acousin           #+#    #+#             */
/*   Updated: 2022/05/27 19:22:29 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/philosophers.h"

void	ft_setup(t_philo *platon)
{
	pthread_mutex_lock(&platon->banquet->death);
	platon->banquet->time_start = get_time();
	platon->banquet->isbegin = 1;
	pthread_mutex_unlock(&platon->banquet->death);
}

void	*ft_philo(void *philo)
{
	int		i;
	t_philo	*platon;

	platon = (t_philo *)philo;
	i = 0;
	if (platon->position + 1 == platon->banquet->seats)
		ft_setup(platon);
	while (1)
	{
		if (ft_isbegin(platon))
			break ;
		usleep(100);
	}
	platon->start = get_time();
	pthread_mutex_lock(&platon->mealmutex);
	platon->lastmeal = get_time();
	pthread_mutex_unlock(&platon->mealmutex);
	if (platon->position % 2 == 0)
		usleep(5000);
	while (1)
	{
		if (ft_take_forks(platon) == -1)
			return (NULL);
	}
}

int	ft_check_all(t_banquet *banquet)
{
	int	i;

	i = ft_are_dead(banquet);
	if (i != 0)
	{
		ft_message(banquet, DEATH, i);
		return (0);
	}
	else if (banquet->diet != 0 && ft_is_everyone_full(banquet))
	{
		ft_message(banquet, FULL, 0);
		return (0);
	}
	return (1);
}

void	ft_philosophers(t_banquet *banquet)
{
	int	i;

	i = -1;
	if (banquet->seats == 1)
	{
		banquet->time_start = get_time();
		ft_onephilo(banquet);
		return ;
	}
	while (++i < (int)banquet->seats)
	{
		if (pthread_create(&banquet->philos[i].thread,
				NULL, ft_philo, &banquet->philos[i]) != 0)
			return ;
	}
	while (1)
	{
		if (!ft_check_all(banquet))
		{
			i = -1;
			while (++i < (int)banquet->seats)
				pthread_join(banquet->philos[i].thread, NULL);
			break ;
		}
	}
}
