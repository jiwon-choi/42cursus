/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 01:05:48 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/02/03 14:38:41 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int		ft_separate(char **save, char **line, char *join, int n_idx)
{
	*save = ft_strdup(join + n_idx + 1);
	*(join + n_idx) = 0;
	*line = ft_strdup(join);
	free(join);
	return (1);
}

int		rest_after_eof(char **save, char **line, char *join)
{
	int		n_idx;

	if ((n_idx = ft_newline_idx(join)) >= 0)
		return (ft_separate(save, line, join, n_idx));
	*save = 0;
	*line = ft_strdup(join);
	free(join);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	int				read_size;
	char			buf[BUFFER_SIZE + 1];
	static char		*save;
	char			*join;
	int				n_idx;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (ERR);
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = 0;
		join = ft_strjoin(save, buf);
		free(save);
		if ((n_idx = ft_newline_idx(join)) >= 0)
			return (ft_separate(&save, line, join, n_idx));
		save = ft_strdup(join);
		free(join);
	}
	if (read_size < 0)
		return (ERR);
	join = ft_strdup(save);
	free(save);
	return (rest_after_eof(&save, line, join));
}
