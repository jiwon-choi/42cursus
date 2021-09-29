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

	if (argc < 5 || argc > 6)
		return (ft_error("[ERROR] argc"));
	if (init_info(argv, &info))
		return (EXIT_FAILURE);
	if (run(&info))
		return (EXIT_FAILURE);
	pthread_mutex_lock(&info.die_mutex);
	pthread_mutex_unlock(&info.die_mutex);
	return (EXIT_SUCCESS);
}
