/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:36:53 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/09/29 16:57:58 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

# define FORKS 0
# define EAT 1
# define SLEEP 2
# define THINK 3
# define DEAD 4

# define TRUE 1
# define FALSE 0

typedef int		t_bool;

typedef struct s_philo
{
	int				number;
	int				stat;
	int				eat_cnt;
	uint64_t		time;
	pthread_mutex_t	*rfork;
	pthread_mutex_t	*lfork;
	struct s_info	*info;
}					t_philo;

typedef struct s_info
{
	int				number_of_philo;
	uint64_t		time_to_die;
	uint64_t		time_to_eat;
	uint64_t		time_to_sleep;
	int				must_eat;
	uint64_t		start_time;
	t_bool			end;
	t_philo			*philo;
	pthread_mutex_t	*fork_mutex;
	pthread_mutex_t	die_mutex;
	pthread_mutex_t	print_mutex;
}					t_info;

// init.c
void		init_time(t_info *info);
int			init_philo(t_info *info);
int			init_forks(t_info *info);
int			init_info(char **argv, t_info *info);

// monitor.c
void		*monitor_philo(void *philo);

// routine.c
void		take_forks(t_philo *philo);
void		eat(t_philo *philo);
void		sleep_think(t_philo *philo);

// run.c
int			run(t_info *info);

// utils.c
int			ft_error(char *str);
uint64_t	gettimeofnow(void);
int			philo_atoi(char *str);
void		print_status(t_philo *p, char *str);

#endif
