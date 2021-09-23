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

int	error_handler(char *err_msg)
{
	printf("%s\n", err_msg);
	return (EXIT_FAILURE);
}

int	init_info(t_info *info, int *argv_num)
{
	info->philo_cnt = argv_num[0];
	info->time_to_die = argv_num[1];
	info->time_to_eat = argv_num[2];
	info->time_to_sleep = argv_num[3];
	info->must_eat = argv_num[4];
	if (!(info->philo = (t_philo *)malloc(sizeof(t_philo) * info->philo_cnt)))
		return (EXIT_FAILURE);
	if (!(info->fork_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * info->philo_cnt)))
	{
		free(info->philo);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_info		info;
	int			argv_num[5];
	int			i;

	if (argc < 5 || argc > 6)
		return (error_handler("argc error"));
	i = 0;
	while (*(++argv))
	{
		argv_num[i++] = philo_atoi(*argv);
		// 음수 예외처리 미리
	}
	if (init_info(&info, argv_num))
		return (error_handler("info error"));
	printf("%d %d %d %d %d\n", info.philo_cnt, info.time_to_die, info.time_to_eat, info.time_to_sleep, info.must_eat);
	return (EXIT_SUCCESS);
}
