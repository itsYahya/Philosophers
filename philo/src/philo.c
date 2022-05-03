/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 21:06:39 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/05/03 16:50:07 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

void	ft_pthread_trylock(t_mutex *left_fork, t_mutex *right_fork,
	t_philo *philo, int thinking)
{
	if ((left_fork->islock || right_fork->islock) && thinking == 0)
		state_log(philo, " is thinking\n", ft_gettime() - philo->time);
	while (left_fork->islock && right_fork->islock)
		;
	if (left_fork->islock == 0 && right_fork->islock == 0)
	{
		left_fork->islock = 1;
		right_fork->islock = 1;
		pthread_mutex_lock(&left_fork->mutix);
		state_log(philo, " has taken a fork\n", ft_gettime() - philo->time);
		pthread_mutex_lock(&right_fork->mutix);
		state_log(philo, " has taken a fork\n", ft_gettime() - philo->time);
	}
	else if (left_fork->islock == 0)
		ft_lock(left_fork, right_fork, philo);
	else if (right_fork->islock == 0)
		ft_lock(right_fork, left_fork, philo);
}

void	ft_pthread_unlock(t_philo *philo)
{
	pthread_mutex_unlock(&philo->left_fork->mutix);
	philo->left_fork->islock = 0;
	pthread_mutex_unlock(&philo->right_fork.mutix);
	philo->right_fork.islock = 0;
	state_log(philo, " is sleeping\n", ft_gettime() - philo->time);
	usleep(philo->time_to_sleep * 1000);
}

void	*lifetime(void *data)
{
	t_philo	*philo ;
	int		thinking;

	philo = (t_philo *)data;
	philo->lastmeal = ft_gettime();
	philo->time = ft_gettime();
	thinking = 0;
	while (1)
	{
		ft_pthread_trylock(philo->left_fork,
			&philo->right_fork, philo, thinking);
		philo->eating = 1;
		if (!philo->alive)
			break ;
		state_log(philo, " is eating\n", ft_gettime() - philo->time);
		usleep(philo->time_to_eat * 1000);
		if (philo->notpmust_eat > 0)
			philo->notpmust_eat--;
		philo->eating = 0;
		philo->lastmeal = ft_gettime();
		ft_pthread_unlock(philo);
		thinking = 1;
		state_log(philo, " is thinking\n", ft_gettime() - philo->time);
	}
	return (0);
}

void	ft_seewhosdead(t_data *data, int index, int number)
{
	t_philo	*philo;

	usleep(1000);
	while (1)
	{
		index = 0;
		number = 0;
		while (index < data->philos_number)
		{
			philo = &data->philos[index];
			if (((ft_gettime() - philo->lastmeal) > philo->time_to_die)
				&& !philo->eating)
			{
				philo->alive = 0;
				state_log(philo, " died\n", ft_gettime() - philo->time);
				return ;
			}
			number += (philo->notpmust_eat == 0);
			index++;
		}
		if (number == data->philos_number)
			return ;
	}
}
