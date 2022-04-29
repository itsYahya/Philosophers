/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 21:06:39 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/04/29 17:33:36 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

void	state_log(t_philo *philo, char *state)
{
	pthread_mutex_lock(philo->state_mtx);
	ft_putnbr(philo->number, 10, "0123456789");
	ft_putstr(state, 1);
	pthread_mutex_unlock(philo->state_mtx);
}

void	ft_lock(t_mutex *left_fork, t_mutex *right_fork, t_philo *philo)
{
	left_fork->islock = 1;
	pthread_mutex_lock(&left_fork->mutix);
	state_log(philo, " has taken a fork\n");
	pthread_mutex_lock(&right_fork->mutix);
	right_fork->islock = 1;
	state_log(philo, " has taken a fork\n");
	state_log(philo, " is eating\n");
}

void	ft_pthread_trylock(t_mutex *left_fork, t_mutex *right_fork, t_philo *philo, int thinking)
{
	if ((left_fork->islock || right_fork->islock) && thinking == 0)
		state_log(philo, " is thinking\n");
	while (left_fork->islock && right_fork->islock)
		usleep(1000);
	if (left_fork->islock == 0 && right_fork->islock == 0)
	{
		left_fork->islock = 1;
		right_fork->islock = 1;
		pthread_mutex_lock(&left_fork->mutix);
		pthread_mutex_lock(&right_fork->mutix);
		state_log(philo, " has taken a fork\n");
		state_log(philo, " has taken a fork\n");
		state_log(philo, " is eating\n");
	}
	else if (left_fork->islock == 0)
		ft_lock(left_fork, right_fork, philo);
	else if (right_fork->islock == 0)
		ft_lock(right_fork, left_fork, philo);
}

void	*lifetime(void *data)
{
	t_philo	*philo;
	int		thinking;

	thinking = 0;
	while (1)
	{
		philo = (t_philo *)data;
		ft_pthread_trylock(philo->left_fork, &philo->right_fork, philo, 0);
		usleep(philo->time_to_eat * 1000);
		pthread_mutex_unlock(&philo->left_fork->mutix);
		philo->left_fork->islock = 0;
		pthread_mutex_unlock(&philo->right_fork.mutix);
		philo->right_fork.islock = 0;
		state_log(philo, " is sleeping\n");
		usleep(philo->time_to_sleep * 1000);
		thinking = 1;
		state_log(philo, " is thinking\n");
	}
	return (0);
}

void	ft_seewhosdead(t_data data)
{
	int	index;
	int	i;
	
	index = 0;
	i = 0;
	while (index < data.philos_number)
	{
		i += (data.philos[index].time_to_die == 0);
		index++;
		if (index == data.philos_number && i != index)
			i = index = 0;
	}
}


