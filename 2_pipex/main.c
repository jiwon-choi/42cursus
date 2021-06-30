/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 10:54:56 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/06/29 11:38:20 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		ft_stdin(char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		// error
	dup2(file, STDIN_FILENO);
	close(fd);
	return (0);
}

// ./pipex file1 cmd1 cmd2 file2
int		main(int argc, char **argv)
{
	pid_t	pid;
	int		fildes[2];

	pid = fork();
	pipe(fildes);
	if (pid > 0)
	{
		ft_stdin(argv[1]);
		dup2(fildes[WRITE], STDOUT_FILENO);
		close(fildes[READ]);
		close(fildes[WRITE]);
		execve("/bin/cat", 0, 0);
	}
	else if (pid == 0)
	{
		dup2(fildes[READ], STDIN_FILENO);
		ft_stdout(argv[4]);
		close(fildes[READ]);
		close(fildes[WRITE]);
		execve("/usr/bin/wc", 0, 0);
	}
	else
		// error
	return (0);
}
