/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 16:21:28 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/09/25 16:21:29 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor_philo(void *philo)
{
	t_philo		*p;

	p = (t_philo *)philo;
	while (gettimeofnow() < p->time + p->info->time_to_die)
	{
		if (p->info->end_flag)
			return (0);
		usleep(100);
	}
	p->stat = DEAD;
	print_status(p);
	pthread_mutex_unlock(&(p->info->die_mutex));
	return (0);
}

void	*monitor_eat(void *philo)
{
	(void)philo;
	return (0);
}
