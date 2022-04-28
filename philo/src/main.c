/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 17:23:07 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/04/28 05:42:08 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pthread_h.h"
#include <unistd.h>
#include <sys/time.h>


void	state_log(t_philo *philo, char *state)
{
	pthread_mutex_lock(philo->state_mtx);
	struct timeval curr;
	time_t tm;
	tm = curr.tv_sec;
	gettimeofday(&curr, NULL);
	printf("%ld\n", tm);
	ft_putnbr(philo->number, 10, "0123456789");
	ft_putstr(state, 1);
	pthread_mutex_unlock(philo->state_mtx);
}

void	*lifetime(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	pthread_mutex_lock(philo->left_fork);
	state_log(philo, " has taken a fork\n");
	pthread_mutex_lock(&philo->right_fork);
	state_log(philo, " has taken a fork\n");
	while (philo->time_to_die)
		philo->time_to_die--;
	state_log(philo, " ended \n");
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(&philo->right_fork);
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
		ft_destroy_mutix(data);
	}
	return (0);
}