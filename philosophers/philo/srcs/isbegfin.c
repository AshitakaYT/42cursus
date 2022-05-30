/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isbegfin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:10:44 by aucousin          #+#    #+#             */
/*   Updated: 2022/05/27 19:11:00 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/philosophers.h"

int	ft_isbegin(t_philo *platon)
{
	pthread_mutex_lock(&platon->banquet->death);
	if (platon->banquet->isbegin == 1)
	{
		pthread_mutex_unlock(&platon->banquet->death);
		return (1);
	}
	pthread_mutex_unlock(&platon->banquet->death);
	return (0);
}

int	ft_isfinished(t_banquet *banquet)
{
	pthread_mutex_lock(&banquet->death);
	if (banquet->isfinished == 1)
	{
		pthread_mutex_unlock(&banquet->death);
		return (1);
	}
	pthread_mutex_unlock(&banquet->death);
	return (0);
}
