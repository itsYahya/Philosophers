/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 17:23:16 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/04/25 23:45:01 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>

typedef struct s_philo
{
	pthread_mutex_t	right_fork;
	pthread_mutex_t	*left_fork;
	pthread_t		thrid;
	int				time_to_eat;
	int				time_to_die;
	int				time_to_sleep;
	int				philos_number;
	int				notpmust_eat;
	int				number;
}	t_philo;

typedef struct s_data
{
	int		philos_number;
	t_philo	*philos;
	void	*data__;
}	t_data;

int		ft_atoi(char *num);
int		ft_init(t_data *data, char **args);


#endif