/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 23:29:06 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/11/18 03:40:10 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_b.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	state_log(t_philo *philo, char *state, long time)
{
	sem_wait(philo->print);
	printf("%ld %d%s", time, philo->number, state);
	sem_post(philo->print);
}

int	ft_starter(t_data *data)
{
	int	index;
	int	pid;

	data->pids = (int *)malloc(sizeof(int) * data->philos_number);
	if (!data->pids)
		return (free(data->philos), 1);
	index = 0;
	while (index < data->philos_number)
	{
		data->philos[index].forks = data->forks;
		data->philos[index].meals = data->meals;
		data->philos[index].print = data->print;
		data->philos[index].time = ft_gettime();
		pid = fork();
		if (pid == 0)
			ft_lifetime(&data->philos[index]);
		data->pids[index] = pid;
		index++;
	}
	if (pthread_create(&data->thread, 0, ft_countmeals, data))
		return (free(data->pids), free(data->philos), exit(1), 1);
	return (0);
}
