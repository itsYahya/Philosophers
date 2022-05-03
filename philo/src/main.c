/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 17:23:07 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/05/03 14:39:32 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pthread_h.h"
#include <unistd.h>
#include <sys/time.h>

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 5 || argc == 6)
	{
		if (ft_init(&data, argv + 1))
			return (ft_putstr("one of the arguments is not correct\n", 2), 1);
		if (ft_init_mutix(&data))
			return (free(data.philos),
				ft_putstr("failed to initialise mutex\n", 2), 1);
		if (ft_init_thread(data))
			return (free(data.philos),
				ft_putstr("failed to run threads\n", 2), 1);
		ft_seewhosdead(&data, 0, 0);
		ft_destroy_mutix(data);
		free(data.philos);
	}
	return (0);
}
