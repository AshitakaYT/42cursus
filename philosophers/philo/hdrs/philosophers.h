/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:24:24 by acousin           #+#    #+#             */
/*   Updated: 2022/05/27 21:10:13 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# define EAT 1
# define FORK 2
# define SLEEP 3
# define THINK 4
# define DEATH 5
# define FULL 6
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	unsigned int		position;
	unsigned int		meals;
	unsigned int		start;
	long				lastmeal;
	unsigned int		death;
	pthread_t			thread;
	pthread_mutex_t		mealmutex;
	pthread_mutex_t		mealsmutex;
	pthread_mutex_t		lfork;
	pthread_mutex_t		*rfork;
	struct s_banquet	*banquet;
}				t_philo;

typedef struct s_banquet
{
	unsigned int	seats;
	unsigned int	die;
	unsigned int	eat;
	unsigned int	sleep;
	unsigned int	diet;
	pthread_mutex_t	message;
	pthread_mutex_t	death;
	int				isbegin;
	int				isfinished;
	unsigned int	time_start;
	t_philo			*philos;
}				t_banquet;

// init

int				ft_parsing_chars(int ac, char **av);
void			ft_init_philos(t_banquet *banquet);
void			ft_init_banquet(t_banquet *banquet, int ac, char **av);

// family

//void	parent_process(int f2, char *cmd2);

// actions

int				ft_take_forks(t_philo *platon);
void			ft_eat(t_philo *platon);
void			ft_sleep(t_philo *platon);
int				ft_message(t_banquet *banquet, int action, int id);

// utils
int				ft_atoi(const char *str);
int				ft_isdigit(int c);
char			*ft_tabjoin(int size, char **strs, char *sep);
int				ft_tablen(char **tab);
void			ft_print_tab(char **tab);
void			ft_onephilo(t_banquet *banquet);

// init

int				ft_zero(char **av);

// end

int				ft_is_everyone_full(t_banquet *banquet);
int				ft_are_dead(t_banquet *banquet);
int				ft_is_dead(t_philo *philo);
void			ft_destroy_philos(t_banquet *banquet);
void			ft_destroy_banquet(t_banquet *banquet);

// time

unsigned int	get_time(void);
int				ft_usleep_improved(long time);
int				ft_usleep_improved2(long time);

// philo

int				ft_isbegin(t_philo *platon);
void			ft_setup(t_philo *platon);
void			*ft_philo(void *philo);
int				ft_check_all(t_banquet *banquet);
void			ft_philosophers(t_banquet *banquet);

// isbegfin

int				ft_isbegin(t_philo *platon);
int				ft_isfinished(t_banquet *banquet);

#endif