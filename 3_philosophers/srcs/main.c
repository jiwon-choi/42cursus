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

#include "../includes/philo.h"

int		error_handler(char *err_msg)
{
	printf("%s\n", err_msg);
	return (EXIT_FAILURE);
}

int		init_info(int argc, char **argv, t_info *info)
{
	if ((info->philo_cnt = philo_atoi(argv[1])) < 2)
		return (-1);
	if ((info->time_to_die = philo_atoi(argv[2])) < 0)
		return (-1);
	if ((info->time_to_eat = philo_atoi(argv[3])) < 0)
		return (-1);
	if ((info->time_to_sleep = philo_atoi(argv[4])) < 0)
		return (-1);
	info->must_eat = 0;
	if (argc == 6 && ((info->must_eat = philo_atoi(argv[5])) < 0))
			return (-1);
	if (info->philo = (t_philo *)malloc(sizeof(t_philo) * info->philo_cnt))
		return (-1);
	if (info->fork_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * info->philo_cnt))
		return (-1);
	return (0);
}

int		main(int argc, char **argv)
{
	t_info		info;

	if (argc < 5 || argc > 6)
		return (error_handler("argc error"));
	if (init_info(argc, argv, &info) == -1)
		return (error_handler("input error"));
	
	printf("%d %d %d %d %d\n", info.philo_cnt, info.time_to_die, info.time_to_eat, info.time_to_sleep, info.must_eat);
	return (0);
}