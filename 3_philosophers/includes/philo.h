/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 11:49:20 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/09/22 15:34:29 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h> //memset
# include <stdio.h> //printf
# include <sys/time.h> // gettimeofday
# include <pthread.h>

typedef struct	s_philo
{
	int			pnum;
	int			philo_stat;
	int			eat_cnt;
}				t_philo;

typedef struct			s_info
{
	int					philo_cnt;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					must_eat;
	t_philo				*philo;
	pthread_mutex_t		*fork_mutex;
}						t_info;

#endif
