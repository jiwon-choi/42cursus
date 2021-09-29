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
