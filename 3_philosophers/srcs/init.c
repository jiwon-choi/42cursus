#include "../includes/philo.h"

int	init_philo(t_info *info)
{
	int	i;

	i = 0;
	if (!(info->philo = (t_philo *)malloc(sizeof(t_philo) * info->number_of_philo)))
		return (EXIT_FAILURE);
	while (++i <= info->number_of_philo)
	{
		info->philo->number = i;
		info->philo->stat = THINK;
		info->philo->eat_cnt = 0;
		info->philo->info = info;
	}
}

int	init_mutex(t_info *info)
{
	int	i;

	if (!(info->fork_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * info->number_of_philo)))
	{
		free(info->philo);
		return (EXIT_FAILURE);
	}
	i = -1;
	while (++i < info->number_of_philo)
		pthread_mutex_init(info->fork_mutex + i, NULL);
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
			return (error_handler("[Error] argv"));
	}
	info->number_of_philo = argv_num[0];
	info->time_to_die = argv_num[1];
	info->time_to_eat = argv_num[2];
	info->time_to_sleep = argv_num[3];
	info->must_eat = argv_num[4];
	init_philo(info);
	init_mutex(info);
	return (EXIT_SUCCESS);
}