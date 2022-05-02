/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 08:37:43 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/05/02 17:16:27 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pthread_h.h"

int	ft_init_mutix(t_data *data)
{
	int	index;

	index = 0;
	if (pthread_mutex_init(&data->state_mtx, NULL))
		return (1);
	while (index < data->philos_number)
	{
		if (pthread_mutex_init(&data->philos[index].right_fork.mutix, NULL))
			return (1);
		data->philos[index].right_fork.islock = 0;
		data->philos[index].state_mtx = &data->state_mtx;
		data->philos[index].eating = 0;
		index++;
	}
	index = 1;
	while (index < data->philos_number)
	{
		data->philos[index].left_fork = &data->philos[index - 1].right_fork;
		index++;
	}
	data->philos[0].left_fork = &data->philos[index - 1].right_fork;
	return (0);
}

int	ft_init_thread(t_data data)
{
	int	index;

	index = 0;
	while (index < data.philos_number)
	{
		if (pthread_create(&data.philos[index].thrid,
				NULL, lifetime, &data.philos[index]))
			return (1);
		index++;
	}
	index = 0;
	while (index < data.philos_number)
		if (pthread_detach(data.philos[index++].thrid))
			return (1);
	return (0);
}

void	ft_destroy_mutix(t_data data)
{
	int	index;

	index = 0;
	pthread_mutex_destroy(&data.state_mtx);
	while (index < data.philos_number)
		pthread_mutex_destroy(&data.philos[index++].right_fork.mutix);
}
