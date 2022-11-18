/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sema_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:16:51 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/11/18 03:41:08 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_b.h"

int	ft_init_sema(t_data *data)
{
	ft_unlik_sem();
	data->forks = sem_open("forks", O_CREAT,
			S_IRUSR | S_IRWXU, data->philos_number);
	if (data->forks == SEM_FAILED)
		return (1);
	data->print = sem_open("print", O_CREAT, S_IRUSR | S_IRWXU, 1);
	if (data->print == SEM_FAILED)
		return (1);
	data->meals = sem_open("meals", O_CREAT, S_IRUSR | S_IRWXU, 0);
	if (data->meals == SEM_FAILED)
		return (1);
	return (0);
}

void	ft_unlik_sem(void)
{
	sem_unlink("forks");
	sem_unlink("print");
	sem_unlink("meals");
}
