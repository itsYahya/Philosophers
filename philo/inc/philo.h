/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 17:23:16 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/04/30 02:35:43 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>

pthread_mutex_t	state_mtx_;

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
}	t_philo;

typedef struct s_data
{
	int				philos_number;
	long			time;
	pthread_mutex_t	state_mtx;
	t_philo			*philos;
}	t_data;

int		ft_atoi(char *num);
int		ft_init(t_data *data, char **args);
int		ft_strlen(char *str);
void	ft_putstr(char *str, int fd);
void	ft_putnbr(long num, int blen, char *base);
void	state_log(t_philo *philo, char *state);
void	*lifetime(void *data);
void	ft_seewhosdead(t_data *data);
long	ft_gettime(void);
void	ft_init_time(t_data *data);

#endif