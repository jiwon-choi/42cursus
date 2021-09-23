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

void	*philo_work(void *param)
{

	return (0);
}

int		run_thread(t_info *info)
{
	pthread_t	tid;
	int			i;

	i = 0;
	while (i++ < info->philo_cnt)
	{
		pthread_create(&tid, NULL, philo_work, NULL);
		pthread_detach(tid);
	}
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
