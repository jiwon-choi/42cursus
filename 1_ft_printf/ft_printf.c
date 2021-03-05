/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 10:26:22 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/02/14 17:55:17 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init(t_flag *data)
{
	data->left = 0;
	data->zero = 0;
	data->width = 0;
	data->dot = 0;
	data->precision = 0;
	data->padding = ' ';
}

void	ft_putchar_fd_iter(char ch, int fd, int len)
{
	while (len-- > 0)
		ft_putchar_fd(ch, fd);
}

int		ft_print_width(t_flag *data, char *src, int len)
{
	int		cnt;

	cnt = ft_strlen(src);
	if (len > 0)
	{
		cnt += len;
		if (data->left)
		{
			ft_putstr_fd(src, 1);
			ft_putchar_fd_iter(data->padding, 1, len);
		}
		else
		{
			if (src[0] == '-' && data->padding == '0')
				ft_putchar_fd(*src++, 1);
			ft_putchar_fd_iter(data->padding, 1, len);
			ft_putstr_fd(src, 1);
		}
	}
	else
		ft_putstr_fd(src, 1);
	return (cnt);
}

int		ft_printf(const char *fmt, ...)
{
	va_list		ap;
	t_flag		data;
	int			cnt;

	va_start(ap, fmt);
	ft_init(&data);
	cnt = 0;
	while (*fmt)
	{
		if (*fmt != '%')
		{
			ft_putchar_fd(*fmt++, 1);
			cnt++;
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
