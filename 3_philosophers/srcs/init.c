#include "philo.h"

void	init_philo(t_info *info)
{
	int	i;

	i = 0;
	while (i <= info->philo_cnt)
	{
		info->philo->number = i + 1;
		info->philo->stat = THINK;
		info->philo->eat_cnt = 0;
		info->philo->info = info;
		pthread_mutex_init(info->fork_mutex + i, NULL);
		i++;
	}
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
			return (EXIT_FAILURE);
	}
	info->philo_cnt = argv_num[0];
	info->time_to_die = argv_num[1];
	info->time_to_eat = argv_num[2];
	info->time_to_sleep = argv_num[3];
	info->must_eat = argv_num[4];
	if (!(info->philo = (t_philo *)malloc(sizeof(t_philo) * info->philo_cnt)))
		return (EXIT_FAILURE);
	if (!(info->fork_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * info->philo_cnt)))
	{
		free(info->philo);
		return (EXIT_FAILURE);
	}
	init_philo(&info);
	return (EXIT_SUCCESS);
}