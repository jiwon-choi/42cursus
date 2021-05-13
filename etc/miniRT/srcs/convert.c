/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 15:05:46 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/05/04 14:56:48 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	comma(char **str)
{
	if (**str != ',')
		return ;
	(*str)++;
}

int		rt_atoi(char **str)
{
	int			sign;
	long long	num;

	sign = 1;
	num = 0;
	while (ft_isspace(**str))
		*str += 1;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
		{
			sign *= -1;
			*str += 1;
		}
	}
	while (ft_isdigit(**str))
	{
		num *= 10;
		num += (*(*str)++ - '0');
	}
	return (num * sign);
}

double	rt_atof(char **str)
{
	int			sign;
	int			n;
	double		num;

	sign = 1;
	num = 0;
	n = -1;
	while (ft_isspace(**str))
		*str += 1;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
		{
			sign *= -1;
			*str += 1;
		}
	}
	while (ft_isdigit(**str))
	{
		num *= 10;
		num += (*(*str)++ - '0');
	}
	if (**str == '.')
	{
		*str += 1;
		while (ft_isdigit(**str))
			num += ((*(*str)++ - '0') * pow(10, n--));
	}
	return (num * sign);
}

t_p3	rt_ato3(char **str)
{
	t_p3	p;

	while (ft_isspace(**str))
		*str += 1;
	p.x = rt_atof(str);
	comma(str);
	p.y = rt_atof(str);
	comma(str);
	p.z = rt_atof(str);
	return (p);
}

int		rt_color(char **str)
{
	int		color;

	color = 0;
	while (ft_isspace(**str))
		*str += 1;
	color += rt_atoi(str);
	color <<= 8;
	comma(str);
	color += rt_atoi(str);
	color <<= 8;
	comma(str);
	color += rt_atoi(str);
	return (color);
}