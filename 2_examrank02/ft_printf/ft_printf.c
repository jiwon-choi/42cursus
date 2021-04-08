/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 10:26:22 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/03/05 20:01:22 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct	s_flag
{
	int		width;
	int		dot;
	int		precision;
}				t_flag;

void	ft_init(t_flag *data)
{
	data->width = 0;
	data->dot = 0;
	data->precision = 0;
}

int		ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		ft_atoi_double(const char **nptr)
{
	int			i;
	int			sign;
	long long	num;

	i = 0;
	sign = 1;
	num = 0;
	if (**nptr == '-' || **nptr == '+')
	{
		if (**nptr == '-')
			sign *= -1;
		i++;
	}
	while (**nptr >= '0' && **nptr <= '9')
	{
		num *= 10;
		num += (*(*nptr)++ - '0');
	}
	return (num * sign);
}

int		ft_div_base(long long num, int num_len, char *base, int base_len)
{
	int		cnt = 0;

	if (num_len == 0)
		return (0);
	cnt += ft_div_base(num / base_len, num_len - 1, base, base_len);
	cnt += write(1, &base[num % base_len], 1);
	return (cnt);
}

int		ft_get_len_base(long long n, int base)
{
	int		len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		len++;
		n /= base;
	}
	return (len);
}

int		ft_type_x(va_list ap, t_flag *data)
{
	long long	num = va_arg(ap, unsigned int);
	int	num_len = ft_get_len_base(num, 16);

	if (data->dot && data->precision == 0 && num == 0)
		num_len = 0;
	else if (data->dot && data->precision > num_len)
		num_len = data->precision;

	int len = data->width - num_len;
	int cnt = 0;
	while (len-- > 0)
		cnt += write(1, " ", 1);

	cnt += ft_div_base(num, num_len, "0123456789abcdef", 16);
	return (cnt);
}

int		ft_type_d(va_list ap, t_flag *data)
{
	long long	num = va_arg(ap, int);
	int	num_len = ft_get_len_base(num, 10);

	if (data->dot && data->precision == 0 && num == 0)
		num_len = 0;
	else if (data->dot && data->precision > num_len)
		num_len = data->precision;

	int len = data->width - num_len;
	if (num < 0) len--;
	int cnt = 0;
	while (len-- > 0)
		cnt += write(1, " ", 1);

	if (num < 0)
	{
		cnt += write(1, "-", 1);
		num *= -1;
	}

	cnt += ft_div_base(num, num_len, "0123456789", 10);
	return (cnt);
}

int		ft_type_str(va_list ap, t_flag *data)
{
	char	*str;
	int		str_len;
	int		cnt = 0;

	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	str_len = ft_strlen(str);
	if (data->dot && data->precision >= 0 && data->precision <= str_len)
		str_len = data->precision;

	int len = data->width - str_len;
	while (len-- > 0)
		cnt += write(1, " ", 1);
	cnt += write(1, str, str_len);
	return (cnt);
}

int		ft_parse(const char **fmt, va_list ap, t_flag *data)
{
	if (**fmt >= '0' && **fmt <= '9')
		data->width = ft_atoi_double(fmt);

	if (**fmt == '.')
	{
		(*fmt)++;
		data->dot = 1;
		if (**fmt >= '0' && **fmt <= '9')
			data->precision = ft_atoi_double(fmt);
	}

	if (**fmt == 'd')
		return (ft_type_d(ap, data));
	else if (**fmt == 'x')
		return (ft_type_x(ap, data));
	else if (**fmt == 's')
		return (ft_type_str(ap, data));
	return (0);
}

int		ft_printf(const char *fmt, ...)
{
	va_list		ap;
	t_flag		data;
	int			cnt = 0;

	va_start(ap, fmt);
	ft_init(&data);
	while (*fmt)
	{
		if (*fmt != '%')
		{
			cnt += write(1, fmt++, 1);
			continue;
		}
		fmt++;
		cnt += ft_parse(&fmt, ap, &data);
		fmt++;
		ft_init(&data);
	}
	va_end(ap);
	return (cnt);
}
