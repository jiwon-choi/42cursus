#include "../includes/philo.h"

void	take_forks(t_philo *p)
{
	pthread_mutex_lock(&(p->info->fork_mutex[p->number - 1]));
	p->stat = FORKS;
	//
	pthread_mutex_lock(&(p->info->fork_mutex[p->number]));
	print_status("has taken a fork");
}

void	eat(t_philo *p)
{
	p->stat = EAT;
	print_status("is eating");
	p->eat_cnt++;
}

void	sleep_think(t_philo *p)
{
	pthread_mutex_unlock(&(p->info->fork_mutex[p->number - 1]));
	pthread_mutex_unlock(&(p->info->fork_mutex[p->number]));
	p->stat = SLEEP;
	print_status("is sleeping");
	p->stat = THINK;
	print_status("died");
}
