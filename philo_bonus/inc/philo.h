/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:55:55 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/05/03 15:12:09 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

typedef struct s_philo
{
	long			time_to_eat;
	long			time_to_die;
	long			time_to_sleep;
	long			philos_number;
	long			time;
	long			lastmeal;
	int				notpmust_eat;
	int				number;
	int				alive;
	int				eating;
}	t_philo;

typedef struct s_data
{
	int				philos_number;
	long			time;
	t_philo			*philos;
}	t_data;

long	ft_atoi(char *num, int *err);
int		ft_init(t_data *data, char **args);
int		ft_strlen(char *str);
void	ft_putstr(char *str, int fd);
void	ft_putnbr(long num, int blen, char *base);
int		ft_clone_args(t_data *data, char **args);

#endif