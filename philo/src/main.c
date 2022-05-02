/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 17:23:07 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/05/01 23:04:57 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pthread_h.h"
#include <unistd.h>
#include <sys/time.h>

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
		ft_seewhosdead(&data);
		ft_destroy_mutix(data);
	}
	return (0);
}
