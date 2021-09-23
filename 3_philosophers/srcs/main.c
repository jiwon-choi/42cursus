/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 11:51:59 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/09/22 15:26:58 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_handler(char *err_msg)
{
	printf("%s\n", err_msg);
	return (EXIT_FAILURE);
}

void	*philo_work(void *philo)
{
	t_philo		*p;
	pthread_t	tid;
	
	p = (t_philo *)philo;
	if (!(pthread_create(&tid, NULL, monitor_philo, philo)))
		return ((void *)1);
	while (1)
	{
		take_forks(p);
		eat(p);
		sleep_think(p);
	}
	return ((void *)0);
}

int		thread_philo(t_info *info, int i)
{
	pthread_t	tid;

	while (i < info->philo_cnt)
	{
		if (!(pthread_create(&tid, NULL, philo_work, (void *)(&(info->philo[i])))))
			return (EXIT_FAILURE);
		pthread_detach(tid);
		i += 2;
	}
	// 대기
	return (EXIT_SUCCESS);
}

int		run(t_info *info)
{
	pthread_t	tid;

	if (info->must_eat > 0)
	{
		if (!(pthread_create(&tid, NULL, monitor_eat, (void *)info)))
			return (EXIT_FAILURE);
		pthread_detach(tid);
	}
	if (thread_philo(info, 0) == EXIT_FAILURE ||
		thread_philo(info, 1) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_info		info;

	if (argc < 5 || argc > 6)
		return (error_handler("argc error"));
	if (init_info(argv, &info))
		return (error_handler("info error"));
	// printf("%d %d %d %d %d\n", info.philo_cnt, info.time_to_die, info.time_to_eat, info.time_to_sleep, info.must_eat);
	run_thread(&info);
	return (EXIT_SUCCESS);
}
