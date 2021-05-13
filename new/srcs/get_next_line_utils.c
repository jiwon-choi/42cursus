/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 01:06:05 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/01/26 21:01:06 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

size_t		ft_strlen(const char *s)
{
	size_t		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char		*ft_strjoin(char const *save, char const *buf)
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
		error_check(5, "GNL");
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

int			ft_newline_idx(const char *s)
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

char		*ft_strdup(const char *s)
{
	size_t		l;
	char		*dup;
	int			i;

	if (!s)
	{
		if (!(dup = (char *)malloc(1)))
			error_check(5, "GNL");
		dup[0] = 0;
		return (dup);
	}
	l = ft_strlen(s);
	if (!(dup = (char *)malloc(l + 1)))
		error_check(5, "GNL");
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}
