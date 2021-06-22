/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 13:55:04 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/06/22 20:48:55 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	handler(int sig)
{
	if (sig == 30)
		printf("0 \n");
	else if (sig == 31)
		printf("1 \n");
//	printf("signal no %d!!!\n", sig);
}

int		main(int argc, char **argv)
{
	printf("%d\n", getpid());
	signal(SIGUSR1, (void *)handler);
	signal(SIGUSR2, (void *)handler);
	while (1)
		pause();

	return (0);
}
