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

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->rfork);
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(philo->lfork);
	print_status(philo, "has taken a fork");
}

void	eat(t_philo *philo)
{
	philo->time = gettimeofnow();
	print_status(philo, "is eating");
	while (gettimeofnow() < philo->time + philo->info->time_to_eat)
		usleep(100);
	philo->eat_cnt++;
	pthread_mutex_unlock(philo->lfork);
	pthread_mutex_unlock(philo->rfork);
}

void	sleep_think(t_philo *philo)
{
	uint64_t	sleep_start;

	sleep_start = gettimeofnow();
	print_status(philo, "is sleeping");
	while (gettimeofnow() < sleep_start + philo->info->time_to_sleep)
		usleep(100);
	usleep(50);
	print_status(philo, "is thinking");
}
