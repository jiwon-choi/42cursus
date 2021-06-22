/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 15:36:34 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/06/22 17:13:34 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static int		check_over_range(long long num)
{
	if (num > 32768)
		ft_error();
	if (num < 2)
		ft_error();
	return (num);
}

int				ft_atoi(char *str)
{
	int					sign;
	long long			num;

	sign = 1;
	num = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			ft_error();
		num *= 10;
		num += (*(str++) - '0');
	}
	return (check_over_range(num * sign));
}
