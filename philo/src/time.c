/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 09:11:04 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/04/29 09:19:02 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/time.h>

long	ft_gettime()
{
	struct timeval	tm;
	double			time;
	
	gettimeofday(&tm, NULL);
	time = ((double)tm.tv_usec / 1000);
	time += tm.tv_sec * 1000;
	return (time);
}
