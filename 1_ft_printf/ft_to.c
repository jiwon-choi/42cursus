/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 10:53:36 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/02/17 01:27:52 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi_double(const char **nptr)
{
	int			i;
	int			sign;
	long long	num;

	i = 0;
	sign = 1;
	num = 0;
	while (ft_isspace(**nptr))
		*nptr += 1;
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

char	*ft_itoa_data(int n, t_flag *data)
{
	long long	num;
	char		*str;
	int			len;

	num = n;
	len = ft_get_len_base(num, 10);
	len = len > data->precision ? len : data->precision;
	if (num < 0)
		len += 1;
	if (!(str = (char *)ft_calloc(len + 1, 1)))
		return (0);
	if (num < 0)
	{
		str[0] = '-';
		num *= -1;
	}
	str[len--] = 0;
	while (1)
	{
		if (str[len] == '-' || len < 0)
			break ;
		str[len--] = '0' + num % 10;
		num /= 10;
	}
	return (str);
}

char	*ft_uitoa_base(unsigned int n, char *base, t_flag *data)
{
	long long	num;
	char		*str;
	int			base_len;
	int			len;

	num = n;
	base_len = ft_strlen(base);
	len = ft_get_len_base(num, base_len);
	len = len > data->precision ? len : data->precision;
	if (!(str = (char *)malloc(len + 1)))
		return (0);
	if (num == 0)
		str[0] = '0';
	str[len--] = 0;
	while (len >= 0)
	{
		str[len--] = base[num % base_len];
		num /= base_len;
	}
	return (str);
}

char	*ft_ultoa_base(unsigned long n, char *base, t_flag *data)
{
	long long	num;
	char		*str;
	int			base_len;
	int			len;

	num = n;
	base_len = ft_strlen(base);
	len = ft_get_len_base(num, base_len);
	len = len > data->precision ? len : data->precision;
	if (!(str = (char *)malloc(len + 1)))
		return (0);
	if (num == 0)
		str[0] = '0';
	str[len--] = 0;
	while (len >= 0)
	{
		str[len--] = base[num % base_len];
		num /= base_len;
	}
	return (str);
}
