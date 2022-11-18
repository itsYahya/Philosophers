/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_b.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:55:55 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/11/18 03:37:11 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_B_H
# define PHILO_B_H

# include <semaphore.h>
# include <pthread.h>

typedef struct s_philo
{
	pthread_t	thread;
	sem_t		*forks;
	sem_t		*print;
	sem_t		*meals;
	long		time_to_eat;
	long		time_to_die;
	long		time_to_sleep;
	long		philos_number;
	long		time;
	long		lastmeal;
	int			notpmust_eat;
	int			number;
	int			alive;
	int			eating;
}	t_philo;

typedef struct s_data
{
	int			philos_number;
	long		time;
	int			*pids;
	sem_t		*forks;
	sem_t		*print;
	sem_t		*meals;
	pthread_t	thread;
	t_philo		*philos;
}	t_data;

long	ft_atoi(char *num, int *err);
int		ft_init(t_data *data, char **args);
int		ft_strlen(char *str);
void	ft_putstr(char *str, int fd);
void	ft_putnbr(long num, int blen, char *base);
int		ft_clone_args(t_data *data, char **args);
int		ft_init_sema(t_data *data);
void	ft_unlik_sem(void);
void	ft_usleep(long tosleep);
void	state_log(t_philo *philo, char *state, long time);
long	ft_gettime(void);
int		ft_starter(t_data *data);
void	ft_lifetime(t_philo *philo);
void	*ft_countmeals(void *data);
void	ft_kill(t_data *data);

#endif