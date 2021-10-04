/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 16:21:40 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/10/04 17:21:50 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_error(char *str)
{
	printf("%s\n", str);
	return (EXIT_FAILURE);
}

uint64_t	gettimeofnow(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
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

void	print_status(t_philo *p, char *str)
{
	if (!p->info->end)
	{
		pthread_mutex_lock(&(p->info->print_mutex));
		printf("%lldms	%d %s	[%d]\n", gettimeofnow() - p->info->start_time,
			p->number, str, p->eat_cnt);
		if (str[0] == 'd' || p->stat == 10)
			p->info->end = TRUE;
	}
	if (!p->info->end)
		pthread_mutex_unlock(&(p->info->print_mutex));
}
