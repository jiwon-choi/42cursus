/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 15:36:34 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/05/25 15:46:54 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int		check_over_range(long long num, int sign)
{
	if (num > 2147483647)
		ft_error();
	if (num < -2147483648)
		ft_error();
	return (num * sign);
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
	return (check_over_range(num, sign));
}
