/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:59:02 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/11/18 03:39:30 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_b.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

static void	*ft_death(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (1)
	{
		if (ft_gettime() - philo->lastmeal > philo->time_to_die)
		{
			state_log(philo, " died\n", ft_gettime() - philo->time);
			exit(1);
		}
		usleep(100);
	}
	return (0);
}

static void	ft_day(t_philo *philo)
{
	sem_wait(philo->forks);
	state_log(philo, " has taken a fork\n", ft_gettime() - philo->time);
	sem_wait(philo->forks);
	state_log(philo, " has taken a fork\n", ft_gettime() - philo->time);
	state_log(philo, " is eating\n", ft_gettime() - philo->time);
	philo->lastmeal = ft_gettime();
	ft_usleep(philo->time_to_eat);
}

static void	ft_night(t_philo *philo)
{
	sem_post(philo->forks);
	sem_post(philo->forks);
	state_log(philo, " is sleeping\n", ft_gettime() - philo->time);
	ft_usleep(philo->time_to_sleep);
}

static void	ft_checkmeals(t_philo *philo)
{
	if (philo->notpmust_eat == -1)
		return ;
	if (--philo->notpmust_eat == 0)
	{
		sem_post(philo->meals);
		philo->notpmust_eat = -1;
	}
}

void	ft_lifetime(t_philo *philo)
{
	if (pthread_create(&philo->thread, NULL, ft_death, philo))
		exit(1);
	philo->lastmeal = ft_gettime();
	if (philo->number % 2)
		ft_usleep(philo->time_to_eat);
	while (1)
	{
		ft_day(philo);
		ft_checkmeals(philo);
		ft_night(philo);
		state_log(philo, " is thinking\n", ft_gettime() - philo->time);
	}
}
