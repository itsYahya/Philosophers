/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 21:06:39 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/05/01 23:36:47 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

void	ft_pthread_trylock(t_mutex *left_fork, t_mutex *right_fork,
	t_philo *philo, int thinking)
{
	if ((left_fork->islock || right_fork->islock) && thinking == 0)
		state_log(philo, " is thinking\n");
	while (left_fork->islock && right_fork->islock)
		;
	if (left_fork->islock == 0 && right_fork->islock == 0)
	{
		left_fork->islock = 1;
		right_fork->islock = 1;
		pthread_mutex_lock(&left_fork->mutix);
		state_log(philo, " has taken a fork\n");
		pthread_mutex_lock(&right_fork->mutix);
		state_log(philo, " has taken a fork\n");
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
	state_log(philo, " is sleeping\n");
	usleep(philo->time_to_sleep * 1000);
}

void	*lifetime(void *data)
{
	t_philo	*philo;
	int		thinking;

	thinking = 0;
	while (1)
	{
		philo = (t_philo *)data;
		ft_pthread_trylock(philo->left_fork,
			&philo->right_fork, philo, thinking);
		philo->lastmeal = -1;
		if (!philo->alive)
			break ;
		state_log(philo, " is eating\n");
		usleep(philo->time_to_eat * 1000);
		if (philo->notpmust_eat > 0)
			philo->notpmust_eat--;
		philo->lastmeal = ft_gettime();
		ft_pthread_unlock(philo);
		thinking = 1;
		state_log(philo, " is thinking\n");
	}
	return (0);
}

int	ft_seewhosdead(t_data *data)
{
	int		index;
	int		number;
	t_philo	philo;

	while (1)
	{
		index = 0;
		number = 0;
		while (index < data->philos_number)
		{
			philo = data->philos[index];
			if (((ft_gettime() - philo.lastmeal) > philo.time_to_die))
			{
				if (philo.lastmeal != -1)
					return (ft_state_die(&philo));
			}
			number += (philo.notpmust_eat == 0);
			index++;
		}
		if (number == data->philos_number)
			return (0);
		usleep(2 * 1000);
	}
	return (0);
}
