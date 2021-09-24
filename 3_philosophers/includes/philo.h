/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 11:49:20 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/09/24 17:18:36 by jiwchoi          ###   ########.fr       */
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

# define FORKS 0
# define EAT 1
# define SLEEP 2
# define THINK 3

typedef struct		s_philo
{
	int				number;
	int				stat;
	int				eat_cnt;
	struct s_info	*info;
}					t_philo;

typedef struct			s_info
{
	int					number_of_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					must_eat;
	t_philo				*philo;
	pthread_mutex_t		*fork_mutex;
}						t_info;

int		init_philo(t_info *info);
int		init_mutex(t_info *info);
int		init_info(char **argv, t_info *info);

int		error_handler(char *err_msg);
void	*philo_work(void *philo);
int		thread_philo(t_info *info, int i);
int		run(t_info *info);

void	*monitor_philo(void *param);
void	*monitor_eat(void *param);

int		philo_atoi(char *str);
void	print_status(char *str);

void	take_forks(t_philo *p);
void	eat(t_philo *p);
void	sleep_think(t_philo *p);

#endif
