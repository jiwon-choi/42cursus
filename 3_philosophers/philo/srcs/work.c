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
	print_status("has taken a fork");
}

void	eat(t_philo *p)
{
	p->stat = EAT;
	print_status("is eating");
	usleep(1000 * p->info->time_to_eat);
	p->eat_cnt++;
}

void	sleep_think(t_philo *p)
{
	pthread_mutex_unlock(&(p->info->fork_mutex[(p->number - 1 + p->info->number_of_philo) % p->info->number_of_philo]));
	pthread_mutex_unlock(&(p->info->fork_mutex[p->number]));
	p->stat = SLEEP;
	print_status("is sleeping");
	usleep(1000 * p->info->time_to_sleep);
	p->stat = THINK;
}
