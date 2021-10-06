/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:46:15 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/10/06 11:20:16 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_destroy(t_info *info)
{
	int		i;

	i = -1;
	while (++i < info->number_of_philo)
		pthread_mutex_destroy(&(info->fork_mutex[i]));
	pthread_mutex_destroy(&(info->die_mutex));
	pthread_mutex_destroy(&(info->print_mutex));
	pthread_mutex_destroy(&(info->count_mutex));
	free(info->fork_mutex);
	free(info->philo);
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc < 5 || argc > 6)
		return (ft_error("[ERROR] argc"));
	if (init_info(argv, &info))
		return (EXIT_FAILURE);
	if (run(&info))
	{
		ft_destroy(&info);
		return (EXIT_FAILURE);
	}
	pthread_mutex_lock(&info.die_mutex);
	pthread_mutex_unlock(&info.die_mutex);
	ft_destroy(&info);
	return (EXIT_SUCCESS);
}
