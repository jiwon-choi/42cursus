/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 10:27:06 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/02/14 16:32:36 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef struct	s_flag
{
	int		left;
	int		zero;
	int		width;
	int		dot;
	int		precision;
	char	padding;
}				t_flag;

void			ft_parse_flag(const char **fmt, t_flag *data);
void			ft_parse_width(const char **fmt, va_list ap, t_flag *data);
void			ft_parse_precision(const char **fmt, va_list ap, t_flag *data);
int				ft_parse(const char **fmt, va_list ap, t_flag *data);
void			ft_init(t_flag *data);
void			ft_putchar_fd_iter(char ch, int fd, int len);
int				ft_print_width(t_flag *data, char *src, int len);
int				ft_printf(const char *fmt, ...);
int				ft_atoi_double(const char **nptr);
int				ft_get_len_base(long long n, int base);
char			*ft_itoa_data(int n, t_flag *data);
char			*ft_uitoa_base(unsigned int n, char *base, t_flag *data);
char			*ft_ultoa_base(unsigned long n, char *base, t_flag *data);
int				ft_type_num(va_list ap, t_flag *data, char type);
int				ft_type_address(va_list ap, t_flag *data);
int				ft_type_str(va_list ap, t_flag *flag);
int				ft_type_char(va_list ap, t_flag *data, char type);

#endif
