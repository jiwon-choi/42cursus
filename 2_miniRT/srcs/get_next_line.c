/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 01:05:48 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/03/29 17:36:24 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*ft_strdup(const char *s)
{
	size_t		l;
	char		*dup;
	int			i;

	if (!s)
	{
		if (!(dup = (char *)malloc(1)))
			return (0);
		dup[0] = 0;
		return (dup);
	}
	l = ft_strlen(s);
	if (!(dup = (char *)malloc(l + 1)))
		return (0);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

char	*ft_strjoin(char const *save, char const *buf)
{
	int		i;
	int		j;
	char	*join;

	if (!save)
	{
		join = ft_strdup(buf);
		return (join);
	}
	if (!(join = (char *)malloc(ft_strlen(save) + ft_strlen(buf) + 1)))
		return (0);
	i = 0;
	j = 0;
	while (save[i])
	{
		join[i] = save[i];
		i++;
	}
	while (buf[j])
		join[i++] = buf[j++];
	join[i] = 0;
	return (join);
}

int		ft_newline_idx(const char *s)
{
	int		idx;

	idx = 0;
	while (s[idx])
	{
		if (s[idx] == '\n')
			return (idx);
		idx++;
	}
	return (-1);
}

int		ft_separate(char **save, char **line, char *join, int n_idx)
{
	*save = ft_strdup(join + n_idx + 1);
	*(join + n_idx) = 0;
	*line = ft_strdup(join);
	free(join);
	return (1);
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
	*line = ft_strdup(save);
	free(save);
	return (0);
}
