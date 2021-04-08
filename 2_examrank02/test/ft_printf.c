#include <stdarg.h>
#include <unistd.h>
#define BASE "0123456789"
#define BASEX "0123456789abcdef"
#define max(a, b) (((a) < (b)) ? (b) : (a))
#define min(a, b) (((a) > (b)) ? (b) : (a))

int		print_size;






int		ft_printf(char *fmt, ...)
{
	va_list		ap;
	int			i = 0;
	int			sign = 0;

	print_size = 0;
	va_start(ap, fmt);
	while (fmt[i])
	{
		int		width = 0;
		int		dot = 0;
		int		pre = 0;
		if (fmt[i] == '%')
		{
			i++;
			while (fmt[i] && fmt[i] != 's' && fmt[i] != 'd' && fmt[i] != 'x')
			{
				if (fmt[i] == '.')
				{
					dot = 1;
					i++;
				}
				for ( ; !dot && fmt[i] >= '0' && fmt[i] <= '9' ; i++)
					width = width * 10 + (fmt[i] - '0');
				for ( ; dot && fmt[i] >= '0' && fmt[i] <= '9' ; i++)
					pre = pre * 10 + (fmt[i] - '0');
			}
			if (fmt[i] == 's')
			{
				char *s = va_arg(ap, char *);
				if (!s)
					s = "(null)";
				if (dot && !pre)
					s = "";
				if (!dot)
					pre = ft_strlen(s);
				for (int idx = 0 ; idx < width - min(ft_strlen(s), pre) ; idx++)
					print_size += write(1, " ", 1);
				for (int idx = 0 ; idx < min(ft_strlen(s), pre) ; idx++)
					print_size += write(1, &s[idx], 1);
			}
			else if (fmt[i] == 'd')
			{
				long long num = va_arg(ap, int);
				if (num < 0)
				{
					num *= -1;
					sign = 1;
				}
				if (num == 0 && dot && !pre)
					width++;
				for (int idx = 0 ; idx < width - sign - max(pre, numlen(num, 10)) ; idx++)
					print_size += write(1, " ", 1);
				if (sign)
					print_size += write(1, "-", 1);
				for (int idx = 0 ; idx < pre - numlen(num, 10) ; idx++)
					print_size += write(1, "0", 1);
				if (num != 0 || dot != 1 || pre != 0)
					ft_putnbr(num, 10, BASE);
			}
			else if (fmt[i] == 'x')
			{
				long long num = va_arg(ap, int);
				if (num == 0 && dot && !pre)
					width++;
				for (int idx = 0 ; idx < width - sign - max(pre, numlen(num, 16)) ; idx++)
					print_size += write(1, " ", 1);
				if (sign)
					print_size += write(1, "-", 1);
				for (int idx = 0 ; idx < pre - numlen(num, 16) ; idx++)
					print_size += write(1, "0", 1);
				if (num != 0 || dot != 1 || pre != 0)
					ft_putnbr(num, 16, BASEX);
			}
			else
				i--;
		}
		else
			print_size += write(1, &fmt[i], 1);
		i++;
	}
	return (print_size);
}
