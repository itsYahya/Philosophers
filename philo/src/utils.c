/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 08:35:36 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/04/25 23:25:58 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_atoi(char *num)
{
	int		index;
	long	number;
	
	number = 0;
	index = 0;
	index += (num[index] == '+');
	while (num[index] <= '9' && num[index] >= '0')
	{
		number = number * 10 + (num[index] - '0');
		index++;
	}
	if (num[index])
		return (0);
	return (number);
}

int	ft_init(t_data *data, char **args)
{
	int	index;		
	
	data->philos_number = ft_atoi(args[0]);
	if (!data->philos_number)
		return (1);
	data->philos = (t_philo *)malloc(sizeof(t_philo) * (data->philos_number));
	data->philos[0].time_to_die = ft_atoi(args[1]);
	data->philos[0].time_to_eat = ft_atoi(args[2]);
	data->philos[0].time_to_sleep = ft_atoi(args[3]);
	if (args[4])
		data->philos[0].notpmust_eat = ft_atoi(args[4]);
	else
		data->philos[0].notpmust_eat = -1;
	index = 1;
	while (index < data->philos_number)
	{
		data->philos[index].time_to_die = data->philos[0].time_to_die;
		data->philos[index].time_to_eat = data->philos[0].time_to_eat;
		data->philos[index].time_to_sleep = data->philos[0].time_to_sleep;
		data->philos[index].notpmust_eat = data->philos[0].notpmust_eat;
		data->philos[index].philos_number = data->philos_number;
		data->philos[index - 1].number = index;
		index++;
	}
	data->philos[index - 1].number = index;
	return (0);
}
