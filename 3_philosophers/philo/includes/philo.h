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
# define DEAD 4

typedef struct		s_philo
{
	int				number;
	int				stat;
	int				eat_cnt;
	unsigned long	time;
	pthread_mutex_t	*rfork;
	pthread_mutex_t	*lfork;
	struct s_info	*info;
}					t_philo;

typedef struct			s_info
{
	int					number_of_philo;
	unsigned long		time_to_die;
	unsigned long		time_to_eat;
	unsigned long		time_to_sleep;
	int					must_eat;
	unsigned long		start_time;
	t_philo				*philo;
	pthread_mutex_t		*fork_mutex;
	pthread_mutex_t		die_mutex;
	pthread_mutex_t		print_mutex;
}						t_info;

void	init_time(t_info *info);
int		init_philo(t_info *info);
int		init_mutex(t_info *info);
int		init_info(char **argv, t_info *info);

int		error_handler(char *err_msg);
void	*philo_work(void *philo);
int		thread_philo(t_info *info, int i);
int		run(t_info *info);

void	*monitor_philo(void *philo);
void	*monitor_eat(void *philo);

//utils.c
unsigned long gettimeofnow(void);
int		philo_atoi(char *str);
void	print_status(t_philo *philo);

void	take_forks(t_philo *p);
void	eat(t_philo *p);
void	sleep_think(t_philo *p);

#endif
