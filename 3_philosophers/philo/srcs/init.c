/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:48:09 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/09/29 19:39:35 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_time(t_info *info)
{
	int	i;

	info->start_time = gettimeofnow();
	i = -1;
	while (++i < info->number_of_philo)
		info->philo[i].time = info->start_time;
}

int	init_philo(t_info *info)
{
	int	i;

	info->philo = (t_philo *)malloc(sizeof(t_philo) * (info->number_of_philo));
	if (!info->philo)
		return (ft_error("[ERROR] philo malloc"));
	i = -1;
	while (++i < info->number_of_philo)
	{
		info->philo[i].number = i + 1;
		info->philo[i].stat = THINK;
		info->philo[i].eat_cnt = 0;
		info->philo[i].rfork = &(info->fork_mutex[i]);
		if (i + 1 == info->number_of_philo)
			info->philo[i].lfork = &(info->fork_mutex[0]);
		else
			info->philo[i].lfork = &(info->fork_mutex[i + 1]);
		info->philo[i].info = info;
	}
	return (EXIT_SUCCESS);
}

int	init_forks(t_info *info)
{
	int	i;

	info->fork_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* info->number_of_philo);
	if (!info->fork_mutex)
		return (ft_error("[ERROR] fork_mutex malloc"));
	i = -1;
	while (++i < info->number_of_philo)
		pthread_mutex_init(&(info->fork_mutex[i]), NULL);
	return (EXIT_SUCCESS);
}

int	init_info(char **argv, t_info *info)
{
	int		argv_num[5];
	int		i;

	i = 0;
	argv_num[4] = -1;
	while (*(++argv))
	{
		argv_num[i] = philo_atoi(*argv);
		if (argv_num[i++] <= 0)
			return (ft_error("[ERROR] argv"));
	}
	info->number_of_philo = argv_num[0];
	info->time_to_die = argv_num[1];
	info->time_to_eat = argv_num[2];
	info->time_to_sleep = argv_num[3];
	info->must_eat = argv_num[4];
	info->end = FALSE;
	if (init_forks(info) || init_philo(info))
		return (EXIT_FAILURE);
	pthread_mutex_init(&(info->die_mutex), NULL);
	pthread_mutex_lock(&(info->die_mutex));
	pthread_mutex_init(&(info->print_mutex), NULL);
	return (EXIT_SUCCESS);
}
