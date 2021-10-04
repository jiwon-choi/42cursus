/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 15:51:49 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/09/29 18:53:51 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *p)
{
	pthread_mutex_lock(p->rfork);
	print_status(p, "has taken a fork");
	pthread_mutex_lock(p->lfork);
	print_status(p, "has taken a fork");
}

void	eat(t_philo *p)
{
	p->time = gettimeofnow();
	print_status(p, "is eating");
	while (gettimeofnow() < p->time + p->info->time_to_eat)
		usleep(100);
	p->eat_cnt++;
	pthread_mutex_lock(&(p->info->count_mutex));
	if (p->eat_cnt == p->info->must_eat)
		p->info->must_eat_cnt++;
	usleep(100);
	pthread_mutex_unlock(&(p->info->count_mutex));
	pthread_mutex_unlock(p->lfork);
	pthread_mutex_unlock(p->rfork);
}

void	sleep_think(t_philo *p)
{
	uint64_t	sleep_start;

	sleep_start = gettimeofnow();
	print_status(p, "is sleeping");
	while (gettimeofnow() < sleep_start + p->info->time_to_sleep)
		usleep(100);
	usleep(50);
	print_status(p, "is thinking");
}
