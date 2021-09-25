/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 16:21:40 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/09/25 16:21:41 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_atoi(char *str)
{
	int		num;

	num = 0;
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (-1);
		num *= 10;
		num += (*(str++) - '0');
	}
	return (num);
}

void	print_status(char *str)
{
	printf("timestamp_in_ms ");
	printf("X ");
	printf("is ");
	printf("%s\n", str);
}
