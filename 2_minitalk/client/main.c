/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 15:45:36 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/06/22 20:31:33 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	convert_binary(int server_pid, char ch)
{
	int		binary[8];
	int		idx;

	idx = 8;
	while (idx > 0)
	{
		binary[--idx] = ch % 2;
		ch /= 2;
	}
	for (int i = 0; i < 8; i++)
	{
		printf("%d ", binary[i]);
		if (binary[i] == 0)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(100);
	}
	printf("\n");
}

void	send_server(int server_pid, char *str)
{
	while (*str)
		convert_binary(server_pid, *str++);
}

int		main(int argc, char **argv)
{
	int		server_pid;

	if (argc != 3)
		ft_error();
	server_pid = ft_atoi(argv[1]);
	send_server(server_pid, argv[2]);
	return (0);
}
