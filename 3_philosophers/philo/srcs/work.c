/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 16:21:44 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/09/25 16:21:45 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *p)
{
	pthread_mutex_lock(&(p->info->fork_mutex[(p->number - 1 + p->info->number_of_philo) % p->info->number_of_philo]));
	p->stat = FORKS;
	pthread_mutex_lock(&(p->info->fork_mutex[p->number]));
	print_status(p);
}

void	eat(t_philo *p)
{
	p->stat = EAT;
	p->time = gettimeofnow();
	print_status(p);
	while (gettimeofnow() <= p->time + p->info->time_to_eat)
		;
	p->eat_cnt++;
	pthread_mutex_unlock(&(p->info->fork_mutex[p->number]));
	pthread_mutex_unlock(&(p->info->fork_mutex[(p->number - 1 + p->info->number_of_philo) % p->info->number_of_philo]));
}

void	sleep_think(t_philo *p)
{
	unsigned long	start_time;

	p->stat = SLEEP;
	start_time = gettimeofnow();
	print_status(p);
	while (gettimeofnow() <= start_time + p->info->time_to_sleep)
		;
	p->stat = THINK;
}
