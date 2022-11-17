/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 03:51:50 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/05/03 14:36:49 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "unistd.h"

int	ft_notpmust_eat(char *arg, int *err)
{
	int	number;

	if (!arg)
		return (-1);
	number = ft_atoi(arg, err);
	if(!number)
		return (-1);
	return (number);
}

int	ft_clone_args(t_data *data, char **args)
{
	int	err;

	err = 0;
	data->philos_number = ft_atoi(args[0], &err);
	if (data->philos_number == 0 || err)
		return (1);
	data->philos = (t_philo *)malloc(sizeof(t_philo) * (data->philos_number));
	if (!data->philos)
		return (1);
	data->philos[0].time_to_die = ft_atoi(args[1], &err);
	data->philos[0].time_to_eat = ft_atoi(args[2], &err);
	data->philos[0].time_to_sleep = ft_atoi(args[3], &err);
	data->philos[0].notpmust_eat = ft_notpmust_eat(args[4], &err);
	if (err || data->philos[0].time_to_die == 0
		|| data->philos[0].time_to_eat == 0
		|| data->philos[0].time_to_sleep == 0)
		return (free(data->philos), err + 1);
	return (0);
}

int	ft_init(t_data *data, char **args)
{
	int	index;		

	if (ft_clone_args(data, args))
		return (1);
	index = 0;
	while (index < data->philos_number)
	{
		data->philos[index].time_to_die = data->philos[0].time_to_die;
		data->philos[index].time_to_eat = data->philos[0].time_to_eat;
		data->philos[index].time_to_sleep = data->philos[0].time_to_sleep;
		data->philos[index].notpmust_eat = data->philos[0].notpmust_eat;
		data->philos[index].philos_number = data->philos_number;
		data->philos[index].number = index + 1;
		index++;
	}
	return (0);
}
