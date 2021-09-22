/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 11:51:59 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/09/22 12:05:39 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
	number_of_philosophers
	time_to_die
	time_to_eat
	time_to_sleep
	number_of_times_each_philosopher_must_eat
*/

void	ft_error(char *err_msg)
{
	printf("%s\n", err_msg);
	exit(1);
}

int		philo_atoi(char *str)
{
	int		num;

	num = 0;
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			ft_error("atoi error");
		num *= 10;
		num += (*(str++) - '0');
	}
	return (num);
}

int		main(int argc, char **argv)
{
	t_philo		philo;

	if (argc < 5 || argc > 6)
		ft_error("argc error");
	philo.philosophers = philo_atoi(argv[1]);	
	philo.time_to_die = philo_atoi(argv[2]);
	philo.time_to_eat = philo_atoi(argv[3]);
	philo.time_to_sleep = philo_atoi(argv[4]);
	if (argc == 6)
		philo.must_eat = philo_atoi(argv[5]);
	else
		philo.must_eat = -1;

	printf("%d %d %d %d %d\n", philo.philosophers, philo.time_to_die, philo.time_to_eat, philo.time_to_sleep, philo.must_eat);
	return (0);
}