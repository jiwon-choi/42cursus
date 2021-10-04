/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:56:56 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/09/29 17:15:14 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor_philo(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	while (gettimeofnow() < p->time + p->info->time_to_die)
		usleep(100);
	p->stat = DEAD;
	print_status(p, "died");
	pthread_mutex_unlock(&(p->info->die_mutex));
	return (0);
}

void	*monitor_must_eat(void *void_info)
{
	t_info	*info;
	t_bool	*check;
	int		i;
	int		cnt;

	info = (t_info *)void_info;
	check = (t_bool *)malloc(sizeof(t_bool) * info->number_of_philo);
	if (!check)
		return ((void *)EXIT_FAILURE);
	memset(check, FALSE, info->number_of_philo);
	i = -1;
	cnt = 0;
	while (++i < info->number_of_philo)
	{
		if (check[i])
			continue ;
		if (info->philo[i].eat_cnt == info->must_eat)
		{
			check[i] = TRUE;
			cnt++;
			if (cnt == info->number_of_philo)
			{
				info->philo[i].stat = 10;
				print_status(info->philo, "full");
				pthread_mutex_unlock(&(info->die_mutex));
				return ((void *)EXIT_SUCCESS);
			}
		}
		if (i == info->number_of_philo - 1)
			i = -1;
		usleep(100);
	}
	return ((void *)EXIT_SUCCESS);
}
