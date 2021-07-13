/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 10:54:56 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/07/13 22:39:19 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_stdin(char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror(file);
		exit(1);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
}

void	ft_stdout(char *file)
{
	int		fd;

	fd = open(file, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror(file);
		exit(1);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
}

void	exe_init(t_exe *exe, char *argv)
{
	char	**tmp;

	tmp = ft_split(argv, ' ');
	exe->cmd[0] = ft_strjoin("/usr/local/bin/", tmp[0]);
	exe->cmd[1] = ft_strjoin("/usr/bin/", tmp[0]);
	exe->cmd[2] = ft_strjoin("/bin/", tmp[0]);
	exe->cmd[3] = ft_strjoin("/usr/sbin/", tmp[0]);
	exe->cmd[4] = ft_strjoin("/sbin/", tmp[0]);
	exe->argv = tmp;
	exe->envp = NULL;
}

void	ft_exe(char *argv)
{
	t_exe	exe;
	int		i;

	i = 0;
	exe_init(&exe, argv);
	while (i++ < 5)
		execve(exe.cmd[i], exe.argv, exe.envp);
	perror(exe.argv[0]);
}

char	*make_path(char **envp, char *cmd)
{
	char	**path_arr;
	char	*path;

	while (*envp)
	{
		if (strncmp(*envp, "PATH=", 5) == 0)
			path_arr = ft_split(*(envp + 5), ':');
		envp++;
	}
	while (*path_arr)
	{
		path = ft_strjoin(*path_arr, cmd);
		if (access(path, X_OK))
		{
			// free(path_arr);
			return (path);
		}
		free(path);
		path_arr++;
	}
	// free(path_arr);
	// error
	return (0);
}

int		main(int argc, char **argv)
{
	pid_t	pid;
	int		fildes[2];
	int		status;

	pipe(fildes);
	pid = fork();
	if (pid == 0)
	{
		ft_stdin(argv[1]);
		dup2(fildes[WRITE], STDOUT_FILENO);
		close(fildes[READ]);
		close(fildes[WRITE]);
		ft_exe(argv[2]);
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		dup2(fildes[READ], STDIN_FILENO);
		ft_stdout(argv[4]);
		close(fildes[READ]);
		close(fildes[WRITE]);
		ft_exe(argv[3]);
	}
	return (0);
}
