/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:47:10 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/03/16 18:02:59 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_check(char *str, int i)
{
	char	ch = str[i--];
	while (i >= 0)
	{
		if (str[i] == ch)
			return (1);
		i--;
	}
	return (0);
}

char	*ft_strcat(char *s1, char *s2)
{
	int i = 0;
	while (s1[i])
		i++;
	while (*s2)
		s1[i++] = *s2++;
	s1[i] = 0;
	return (s1);
}

int		main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	char	*str = ft_strcat(argv[1], argv[2]);
	int		i = 0;
	while (str[i])
	{
		if (!ft_check(str, i))
			write(1, &str[i], 1);
		i++;
	}
	return (0);
}
