/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 17:23:16 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/05/02 17:03:57 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>

typedef struct s_mutex
{
	pthread_mutex_t	mutix;
	int				islock;
}	t_mutex;

typedef struct s_philo
{
	t_mutex			right_fork;
	t_mutex			*left_fork;
	pthread_mutex_t	*state_mtx;
	pthread_t		thrid;
	long			time_to_eat;
	long			time_to_die;
	long			time_to_sleep;
	long			philos_number;
	long			time;
	long			lastmeal;
	int				notpmust_eat;
	int				number;
	int				alive;
	int				eating;
}	t_philo;

typedef struct s_data
{
	int				philos_number;
	long			time;
	pthread_mutex_t	state_mtx;
	t_philo			*philos;
}	t_data;

long	ft_atoi(char *num, int *err);
int		ft_init(t_data *data, char **args);
int		ft_strlen(char *str);
void	ft_putstr(char *str, int fd);
void	ft_putnbr(long num, int blen, char *base);
void	state_log(t_philo *philo, char *state, long time);
int		ft_state_die(t_philo *philo);
void	ft_pthread_unlock(t_philo *philo);
void	ft_pthread_trylock(t_mutex *left_fork, t_mutex *right_fork,
			t_philo *philo, int thinking);
void	ft_lock(t_mutex *left_fork, t_mutex *right_fork, t_philo *philo);
void	ft_pthread_unlock(t_philo *philo);
void	*lifetime(void *data);
void	ft_seewhosdead(t_data *data, int index, int number);
long	ft_gettime(void);

#endif