/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmeals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 00:20:05 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/11/18 03:37:59 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_b.h"
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_kill(t_data *data)
{
	int	index;

	index = 0;
	while (index < data->philos_number)
	{
		kill(data->pids[index], 9);
		index++;
	}
}

void	*ft_countmeals(void *ptr)
{
	t_data	*data;
	int		index;

	index = 0;
	data = (t_data *)ptr;
	while (index < data->philos_number)
	{
		sem_wait(data->meals);
		index++;
	}
	ft_unlik_sem();
	free(data->philos);
	free(data->pids);
	ft_kill(data);
	exit(0);
}
