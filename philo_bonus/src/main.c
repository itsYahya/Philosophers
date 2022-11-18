/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:55:58 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/11/18 03:39:12 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_b.h"
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 5 || argc == 6)
	{
		if (ft_init(&data, argv + 1))
			return (ft_putstr("ops: one of the arguments isnt correct\n", 2), 1);
		if (ft_init_sema(&data))
			return (ft_putstr("ops: failed to initialize semaphores\n", 2), 1);
		if (ft_starter(&data))
			return (ft_putstr("ops: error accured\n", 2), 1);
		waitpid(-1, 0, 0);
		ft_unlik_sem();
		ft_kill(&data);
		free(data.pids);
		free(data.philos);
	}
	return (0);
}
