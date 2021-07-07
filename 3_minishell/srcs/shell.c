/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 18:40:08 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/07/07 19:55:46 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		main(void)
{
	pid_t	pid;
	int		fildes[2];
	int		status;

	pipe(fildes);
	pid = fork();
	if (pid == 0)
	{
		char *prompt;
		char *line = readline(prompt);
		if (ft_strnstr(line, "pwd", ft_strlen(line)))
			execve("/bin/pwd", 0, 0);
		else if (ft_strnstr(line, "exit", ft_strlen(line)))
			return(0);
		printf("%s\n", line);
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		execve("./minishell", 0, 0);
	}
	return (0);
}
