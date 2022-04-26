/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 17:23:07 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/04/25 23:45:15 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pthread_h.h"

void	ft_init_mutix(t_data *data)
{
	int	index;
	
	index = 0;
	while (index < data->philos_number)
	{
		pthread_mutex_init(&data->philos[index].right_fork, NULL);
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
	index  = 0;
	while (index < data.philos_number)
		pthread_join(data.philos[index++].thrid, data.data__);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		err;
	
	if (argc == 5 || argc == 6)
	{
		err = ft_init(&data, argv + 1);
		if (err)
			return (printf("error occurs\n"), 0);
		ft_init_mutix(&data);
		ft_init_thread(data);
	}
	return (0);
}