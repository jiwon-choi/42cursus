/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:16:51 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/03/16 18:20:39 by jiwchoi          ###   ########.fr       */
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

int		ft_strchr(char *str, char ch)
{
	while (*str)
	{
		if (*str == ch)
			return (1);
		str++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	int		i = 0;
	while (argv[1][i])
	{
		if (ft_strchr(argv[2], argv[1][i]) && !ft_check(argv[1], i))
			write(1, &argv[1][i], 1);
		i++;
	}
	return (0);
}
