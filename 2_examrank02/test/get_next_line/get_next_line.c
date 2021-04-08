#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int		cnt = 0;
	while (*str++)
		cnt++;
	return (cnt);
}

int		ft_newline_idx(char *str)
{
	int		i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strdup(char *str)
{
	char	*dup = malloc(ft_strlen(str) + 1);
	int		i = 0;

	while (*str)
		dup[i++] = *str++;
	dup[i] = 0;
	return (dup);
}

char	*ft_strjoin(char *save, char *buf)
{
	if (!save)
		return (ft_strdup(buf));

	char	*join = malloc(ft_strlen(save) + ft_strlen(buf) + 1);
	int		i = 0;

	while (*save)
		join[i++] = *save++;
	while (*buf)
		join[i++] = *buf++;
	join[i] = 0;
	return (join);
}

int		get_next_line(char **line)
{
	static char	*save;
	char		*join;
	char		buf[2];
	int			idx;
	int			read_size;

	while ((read_size = read(0, buf, 1)) > 0)
	{
		buf[read_size] = 0;
		join = ft_strjoin(save, buf);
		free(save);
		if ((idx = ft_newline_idx(join)) >= 0)
		{
			save = ft_strdup(join + idx + 1);
			join[idx] = 0;
			*line = ft_strdup(join);
			free(join);
			return (1);
		}
		save = ft_strdup(join);
		free(join);
	}
	if (read_size < 0)
		return (-1);
	*line = ft_strdup(save);
	free(save);
	save = 0;
	return (0);
}
