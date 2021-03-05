/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 12:19:58 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/02/14 17:20:18 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_type_num(va_list ap, t_flag *data, char type)
{
	char	*src;
	int		cnt;
	int		num;

	src = 0;
	if (data->dot && data->precision >= 0)
		data->padding = ' ';
	num = va_arg(ap, int);
	if (data->dot && data->precision == 0 && num == 0)
		src = ft_strdup("");
	else
	{
		if (type == 'd' || type == 'i')
			src = ft_itoa_data(num, data);
		else if (type == 'u')
			src = ft_uitoa_base(num, "0123456789", data);
		else if (type == 'x')
			src = ft_uitoa_base(num, "0123456789abcdef", data);
		else if (type == 'X')
			src = ft_uitoa_base(num, "0123456789ABCDEF", data);
	}
	cnt = ft_print_width(data, src, data->width - ft_strlen(src));
	free(src);
	return (cnt);
}

int		ft_type_address(va_list ap, t_flag *data)
{
	char			*tmp;
	char			*src;
	int				cnt;
	unsigned long	num;

	num = va_arg(ap, unsigned long);
	if (data->dot && data->precision == 0 && num == 0)
		tmp = ft_strdup("");
	else
		tmp = ft_ultoa_base(num, "0123456789abcdef", data);
	src = ft_strjoin("0x", tmp);
	cnt = ft_print_width(data, src, data->width - ft_strlen(src));
	free(tmp);
	free(src);
	return (cnt);
}

int		ft_type_str(va_list ap, t_flag *data)
{
	char	*tmp;
	char	*src;
	int		cnt;

	tmp = va_arg(ap, char *);
	if (!tmp)
		tmp = ft_strdup("(null)");
	else
		tmp = ft_strdup(tmp);
	if (data->dot && data->precision >= 0)
		src = ft_substr(tmp, 0, data->precision);
	else
		src = ft_strdup(tmp);
	cnt = ft_print_width(data, src, data->width - ft_strlen(src));
	free(tmp);
	free(src);
	return (cnt);
}

int		ft_type_char(va_list ap, t_flag *data, char type)
{
	char	ch;
	int		cnt;

	ch = '%';
	if (type == 'c')
		ch = va_arg(ap, int);
	cnt = 1;
	if (data->width > 1)
	{
		cnt += data->width - 1;
		if (data->left)
		{
			ft_putchar_fd(ch, 1);
			ft_putchar_fd_iter(data->padding, 1, data->width - 1);
		}
		else
		{
			ft_putchar_fd_iter(data->padding, 1, data->width - 1);
			ft_putchar_fd(ch, 1);
		}
	}
	else
		ft_putchar_fd(ch, 1);
	return (cnt);
}
