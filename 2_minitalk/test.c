#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void	handler(int sig)
{
	printf("signal no %d!!!\n", sig);
}

int		main(void)
{
	signal(SIGUSR1, (void *)handler);
	kill(getpid(), SIGUSR1);
	/*
	sigset_t	set;
	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	sigaddset(&set, SIGUSR2);
	sleep(3);
	usleep(3000000);
	*/

	return (0);
}
