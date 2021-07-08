/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 18:40:08 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/07/09 01:40:11 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		main(void)
{
	pid_t	pid;
	int		fildes[2];
	int		status;

	char *prompt;
	char *line = readline(prompt);
	char **arr = ft_split(line, ' ');

	pipe(fildes);
	if (ft_strnstr(arr[0], "exit", ft_strlen(line)))
		exit(0);
	pid = fork();

	if (pid == 0)
	{
		if (ft_strnstr(arr[0], "pwd", ft_strlen(line)))
			execve("/bin/pwd", arr, 0);
		printf("%s\n", line);
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		execve("./minishell", 0, 0);
	}
	return (0);
}
