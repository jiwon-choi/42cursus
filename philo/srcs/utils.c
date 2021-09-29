/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 16:21:40 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/09/25 16:21:41 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	gettimeofnow(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int	philo_atoi(char *str)
{
	int		num;

	num = 0;
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (-1);
		num *= 10;
		num += (*(str++) - '0');
	}
	return (num);
}

void	print_status(t_philo *philo)
{
	char	*str;

	if (!philo->info->end_flag)
	{
		pthread_mutex_lock(&(philo->info->print_mutex));
		if (philo->stat == FORKS)
			str = "has taken a fork";
		else if (philo->stat == EAT)
			str = "is eating";
		else if (philo->stat == SLEEP)
			str = "is sleeping";
		else if (philo->stat == DEAD)
		{
			str = "died";
			philo->info->end_flag = TRUE;
		}
		else
			str = 0;
		printf("%lums %d %s\n", gettimeofnow() - philo->info->start_time,
			philo->number, str);
	}
	if (!philo->info->end_flag)
		pthread_mutex_unlock(&(philo->info->print_mutex));
}
