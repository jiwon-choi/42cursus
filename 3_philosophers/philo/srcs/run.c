/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:49:01 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/09/29 19:41:02 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *philo)
{
	t_philo		*p;
	pthread_t	tid;

	p = (t_philo *)philo;
	if (pthread_create(&tid, NULL, monitor_philo, philo))
		return ((void *)EXIT_FAILURE);
	pthread_detach(tid);
	while (1)
	{
		take_forks(p);
		eat(p);
		sleep_think(p);
		usleep(100);
	}
	return ((void *)EXIT_SUCCESS);
}

int	run_philo(t_info *info, int i)
{
	pthread_t	tid;

	while (i < info->number_of_philo)
	{
		if (pthread_create(&tid, NULL, philo_routine, &(info->philo[i])))
			return (EXIT_FAILURE);
		pthread_detach(tid);
		i += 2;
	}
	usleep(500 * info->time_to_eat);
	return (EXIT_SUCCESS);
}

int	run(t_info *info)
{
	init_time(info);
	if (run_philo(info, 1) || run_philo(info, 0))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
