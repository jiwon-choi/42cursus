/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:46:15 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/09/29 16:47:20 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_info	info;
	int		i;

	if (argc < 5 || argc > 6)
		return (ft_error("[ERROR] argc"));
	if (init_info(argv, &info))
		return (EXIT_FAILURE);
	if (run(&info))
		return (EXIT_FAILURE);
	pthread_mutex_lock(&info.die_mutex);
	pthread_mutex_unlock(&info.die_mutex);
	i = -1;
	while (++i < info.number_of_philo)
		pthread_mutex_destroy(&(info.fork_mutex[i]));
	pthread_mutex_destroy(&(info.die_mutex));
	pthread_mutex_destroy(&(info.print_mutex));
	free(info.fork_mutex);
	free(info.philo);
	return (EXIT_SUCCESS);
}
