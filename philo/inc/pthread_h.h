/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_h.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 22:40:42 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/04/28 01:23:01 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PTHREAD_H_H
# define PTHREAD_H_H

# include "philo.h"

void	*lifetime(void *philo);
void	ft_init_mutix(t_data *data);
int		ft_init_thread(t_data data);
void	ft_destroy_mutix(t_data data);

#endif