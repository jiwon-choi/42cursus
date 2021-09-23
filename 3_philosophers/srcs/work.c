#include "philo.h"

void    take_forks(t_philo *p)
{
	pthread_mutex_lock(&(p->info->fork_mutex[p->number - 1]));
	p->stat = FORKS;
	//
	pthread_mutex_lock(&(p->info->fork_mutex[p->number]));
	//
}

void    eat(t_philo *p)
{
	p->stat = EAT;
	//
}

void    sleep(t_philo *p)
{
	pthread_mutex_unlock(&(p->info->fork_mutex[p->number - 1]));
	pthread_mutex_unlock(&(p->info->fork_mutex[p->number]));
	p->stat = SLEEP;
	//
}

void    think(t_philo *p)
{
	p->stat = THINK;
	//
}
