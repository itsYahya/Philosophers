/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 08:35:36 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/11/18 03:41:17 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_b.h"
#include "unistd.h"

long	ft_atoi(char *num, int *err)
{
	int		index;
	long	number;

	(void)err;
	number = 0;
	index = 0;
	index += (num[index] == '+');
	while (num[index] <= '9' && num[index] >= '0')
	{
		number = number * 10 + (num[index] - '0');
		if (number < 0)
			break ;
		index++;
	}
	*err += (num[index] || (number < 0));
	return (number);
}

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	if (!str)
		return (0);
	while (str[index])
		index++;
	return (index);
}

void	ft_putstr(char *str, int fd)
{
	int	index;

	index = 0;
	if (!str)
		return ;
	write(fd, str, ft_strlen(str));
}

void	ft_putnbr(long num, int blen, char *base)
{
	if (num >= blen)
		ft_putnbr(num / blen, blen, base);
	write(1, &base[num % blen], 1);
}

void	ft_usleep(long tosleep)
{
	long	start;

	start = ft_gettime();
	usleep(tosleep * 0.6);
	while (ft_gettime() - start < tosleep)
		usleep(50);
}
