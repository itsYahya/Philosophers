/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 23:31:54 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/05/03 14:11:38 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

void	state_log(t_philo *philo, char *state, long time)
{
	pthread_mutex_lock(philo->state_mtx);
	printf("%ld %d%s", time, philo->number, state);
	pthread_mutex_unlock(philo->state_mtx);
}

void	ft_lock(t_mutex *left_fork, t_mutex *right_fork, t_philo *philo)
{
	(void)philo;
	left_fork->islock = 1;
	pthread_mutex_lock(&left_fork->mutix);
	state_log(philo, " has taken a fork\n", ft_gettime() - philo->time);
	pthread_mutex_lock(&right_fork->mutix);
	right_fork->islock = 1;
	state_log(philo, " has taken a fork\n", ft_gettime() - philo->time);
}
