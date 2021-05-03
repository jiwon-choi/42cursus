/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 15:05:46 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/05/03 20:13:21 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	comma(char **str)
{
	if (**str != ',')
		return ;
	(*str)++;
}

int		rt_atoi(char **nptr)
{
	int			sign;
	long long	num;

	sign = 1;
	num = 0;
	while (ft_isspace(**nptr))
		*nptr += 1;
	if (**nptr == '-' || **nptr == '+')
	{
		if (**nptr == '-')
		{
			sign *= -1;
			*nptr += 1;
		}
	}
	while (ft_isdigit(**nptr))
	{
		num *= 10;
		num += (*(*nptr)++ - '0');
	}
	return (num * sign);
}

double	rt_atof(char **nptr)
{
	int			sign;
	int			n;
	double		num;

	sign = 1;
	num = 0;
	n = -1;
	while (ft_isspace(**nptr))
		*nptr += 1;
	if (**nptr == '-' || **nptr == '+')
	{
		if (**nptr == '-')
		{
			sign *= -1;
			*nptr += 1;
		}
	}
	while (ft_isdigit(**nptr))
	{
		num *= 10;
		num += (*(*nptr)++ - '0');
	}
	if (**nptr == '.')
	{
		*nptr += 1;
		while (ft_isdigit(**nptr))
			num += ((*(*nptr)++ - '0') * pow(10, n--));
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
