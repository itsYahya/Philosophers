/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 17:23:16 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/04/28 05:18:55 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>

pthread_mutex_t	state_mtx_;

typedef struct s_philo
{
	pthread_mutex_t	right_fork;
	pthread_mutex_t	*state_mtx;
	pthread_mutex_t	*left_fork;
	pthread_t		thrid;
	long			time_to_eat;
	long			time_to_die;
	long			time_to_sleep;
	long			philos_number;
	int				notpmust_eat;
	int				number;
	int				is_th;
}	t_philo;

typedef struct s_data
{
	int				philos_number;
	pthread_mutex_t	state_mtx;
	t_philo			*philos;
}	t_data;

int		ft_atoi(char *num);
int		ft_init(t_data *data, char **args);
int		ft_strlen(char *str);
void	ft_putstr(char *str, int fd);
void	ft_putnbr(int num, int blen, char *base);


#endif