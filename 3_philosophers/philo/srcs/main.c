/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 16:21:23 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/09/25 16:21:25 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_handler(char *err_msg)
{
	printf("%s\n", err_msg);
	return (EXIT_FAILURE);
}

// 철학자 한명 한명이 죽지 않았는지 확인하는 모니터를 만들고, 실제로 먹고 자고 생각하는 함수
void	*philo_work(void *philo)
{
	t_philo		*p;
	pthread_t	tid;
	
	p = (t_philo *)philo;
	if (pthread_create(&tid, NULL, monitor_philo, philo))
		return ((void *)1);
	while (1)
	{
		take_forks(p);
		eat(p);
		sleep_think(p);
	}
	return ((void *)0);
}

// 철학자 1인 1쓰레드 생성
int		thread_philo(t_info *info, int i)
{
	pthread_t	tid;

	while (i < info->number_of_philo)
	{
		if (pthread_create(&tid, NULL, philo_work, (void *)(&(info->philo[i]))))
			return (EXIT_FAILURE);
		pthread_detach(tid);
		i += 2;
	}
	// 대기
	return (EXIT_SUCCESS);
}

// 본격적으로 실행 시작, 최소 식사 횟수가 들어온 경우 먹는 횟수를 카운트하는 모니터 쓰레드 생성
int		run(t_info *info)
{
	pthread_t	tid;

	if (info->must_eat > 0)
	{
		if (pthread_create(&tid, NULL, monitor_eat, (void *)info))
			return (EXIT_FAILURE);
		pthread_detach(tid);
	}
	init_time(info);
	if (thread_philo(info, 1) || thread_philo(info, 0))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc < 5 || argc > 6)
		return (error_handler("[Error] argc"));
	if (init_info(argv, &info))
		return (EXIT_FAILURE);
	run(&info);
	// {
	// 	free(info.philo);
	// 	free(info.fork_mutex);
	// 	return (EXIT_FAILURE);
	// };
	pthread_mutex_lock(&info.die_mutex);
	pthread_mutex_unlock(&info.die_mutex);
	// pthread_mutex_destroy(&info.die_mutex);
	// pthread_mutex_destroy(&info.print_mutex);
	usleep(100000);
	return (EXIT_SUCCESS);
}
