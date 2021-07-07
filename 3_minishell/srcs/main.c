/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 18:40:36 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/07/07 18:49:18 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		main(void)
{
	pid_t	pid;
	int		status;

	write(1, "Hello World!\n", 13);
	pid = fork();
	if (pid == 0) // child
	{
		execve("./minishell", 0, 0);
	}
	else if (pid > 0) // parent
		waitpid(pid, &status, 0);
	return (0);
}
