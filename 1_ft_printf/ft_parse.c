/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 10:32:44 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/02/14 16:59:44 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_flag(const char **fmt, t_flag *data)
{
	while (**fmt == '-' || **fmt == '0')
	{
		if (**fmt == '-')
			data->left = 1;
		else
			data->zero = 1;
		*fmt += 1;
	}
}

void	ft_parse_width(const char **fmt, va_list ap, t_flag *data)
{
	int		num;

	if (**fmt == '*' || ft_isdigit(**fmt))
	{
		if (**fmt == '*')
		{
			num = va_arg(ap, int);
			if (num < 0)
			{
				data->left = 1;
				num *= -1;
			}
			*fmt += 1;
		}
		else
			num = ft_atoi_double(fmt);
		data->width = num;
	}
	if (!data->left && data->zero)
		data->padding = '0';
}

void	ft_parse_precision(const char **fmt, va_list ap, t_flag *data)
{
	if (**fmt == '*' || ft_isdigit(**fmt))
	{
		if (**fmt == '*')
		{
			data->precision = va_arg(ap, int);
			*fmt += 1;
		}
		else
			data->precision = ft_atoi_double(fmt);
	}
}

int		ft_parse(const char **fmt, va_list ap, t_flag *data)
{
	ft_parse_flag(fmt, data);
	ft_parse_width(fmt, ap, data);
	if (**fmt == '.' && (*fmt)++)
	{
		data->dot = 1;
		ft_parse_precision(fmt, ap, data);
	}
	if (ft_strchr("diuxX", **fmt))
		return (ft_type_num(ap, data, **fmt));
	else if (ft_strchr("c%", **fmt))
		return (ft_type_char(ap, data, **fmt));
	else if (**fmt == 'p')
		return (ft_type_address(ap, data));
	else if (**fmt == 's')
		return (ft_type_str(ap, data));
	return (0);
}
