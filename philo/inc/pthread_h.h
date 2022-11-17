/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_h.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 22:40:42 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/05/02 17:15:34 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PTHREAD_H_H
# define PTHREAD_H_H

# include "philo.h"

int		ft_init_mutix(t_data *data);
int		ft_init_thread(t_data *data);
void	ft_destroy_mutix(t_data *data, int philos);

#endif