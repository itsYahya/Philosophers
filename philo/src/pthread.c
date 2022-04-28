/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 08:37:43 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/04/28 05:23:32 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pthread_h.h"

void	ft_init_mutix(t_data *data)
{
	int	index;
	
	index = 0;
	pthread_mutex_init(&data->state_mtx, NULL);
	while (index < data->philos_number)
	{
		pthread_mutex_init(&data->philos[index].right_fork, NULL);
		data->philos[index].state_mtx = &data->state_mtx;
		index++;
	}
	index = 1;
	while (index < data->philos_number)
	{
		data->philos[index].left_fork = &data->philos[index - 1].right_fork;
		index++;
	}
	data->philos[0].left_fork = &data->philos[index - 1].right_fork;
}

int	ft_init_thread(t_data data)
{
	int	index;

	index = 0;
	while (index < data.philos_number)
	{
		if (pthread_create(&data.philos[index].thrid, NULL, lifetime, &data.philos[index]))
			return (1);
		index++;
	}
	index = 0;
	while (index < data.philos_number)
		if (pthread_join(data.philos[index++].thrid, NULL))
			return (1);
	return (0);
}

void	ft_destroy_mutix(t_data data)
{
	int	index;

	index = 0;
	while (index < data.philos_number)
		pthread_mutex_destroy(&data.philos[index++].right_fork);
}