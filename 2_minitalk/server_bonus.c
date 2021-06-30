/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 13:55:04 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/06/30 15:18:36 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig)
{
	static int	data = 0;
	static int	cnt = 0;

	cnt++;
	data <<= 1;
	if (sig == SIGUSR2)
		data += 1;
	if (cnt == 8)
	{
		write(1, &data, 1);
		data = 0;
		cnt = 0;
	}
}

int		main(void)
{
	char	*pid_str;

	pid_str = ft_itoa(getpid());
	write(1, pid_str, ft_strlen(pid_str));
	write(1, "\n", 1);
	signal(SIGUSR1, (void *)handler);
	signal(SIGUSR2, (void *)handler);
	while (1)
		pause();
	return (0);
}
