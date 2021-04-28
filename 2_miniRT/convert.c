#include "minirt.h"

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
			sign *= -1;
	}
	while (**nptr >= '0' && **nptr <= '9')
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
			sign *= -1;
	}
	while (**nptr >= '0' && **nptr <= '9')
	{
		num *= 10;
		num += (*(*nptr)++ - '0');
	}
	if (**nptr == '.')
	{
		*nptr += 1;
		while (**nptr >= '0' && **nptr <= '9')
			num += (*(*nptr)++ - '0') * pow(10, n--);
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
