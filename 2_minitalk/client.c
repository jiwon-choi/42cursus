/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 15:45:36 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/06/23 20:28:26 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	convert_binary(int server_pid, int ch)
{
	int		cnt;

	cnt = 7;
	while (cnt >= 0)
	{
		if ((ch >> cnt & 1) == 0)
			kill(server_pid, SIGUSR1);
		else if ((ch >> cnt & 1) == 1)
			kill(server_pid, SIGUSR2);
		usleep(30);
		cnt--;
	}
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
		ft_error("./client [server PID] [message]");
	server_pid = ft_atoi(argv[1]);
	if (server_pid < 2 || server_pid > 32768)
		ft_error("PID out of range");
	send_server(server_pid, argv[2]);
	return (0);
}
