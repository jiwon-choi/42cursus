#include <unistd.h>
#include <stdarg.h>
#define BASE "0123456789abcdef"
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int		result;

int		ft_strlen(char *str)
{
	int cnt = 0;
	while (*str++)
		cnt++;
	return (cnt);
}

int		ft_numlen(long long n, int base)
{
	int len = 0;

	if (n == 0)
		return (1);
	while (n)
	{
		len++;
		n /= base;
	}
	return (len);
}

void	ft_putnbr(long long n, int base)
{
	if (n >= base)
		ft_putnbr(n / base, base);
	result += write(1, &BASE[n % base], 1);
}

int		ft_printf(char *fmt, ...)
{
	int		i = 0;
	va_list ap;

	va_start(ap, fmt);
	result = 0;

	while (fmt[i])
	{
		int width = 0;
		int pre = 0;
		int dot = 0;
		int sign = 0;

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
				if (!dot)
					pre = ft_strlen(s);
				for (int idx = 0 ; idx < width - min(pre, ft_strlen(s)) ; idx++)
					result += write(1, " ", 1);
				for (int idx = 0 ; idx < min(pre, ft_strlen(s)) ; idx++)
					result += write(1, &s[idx], 1);
			}

			else if (fmt[i] == 'd')
			{
				long long num = va_arg(ap, int);
				if (num < 0)
				{
					sign = 1;
					num *= -1;
				}
				if (num == 0 && dot && pre == 0)
					width++;
				for (int idx = 0 ; idx < width - sign - max(pre, ft_numlen(num, 10)) ; idx++)
					result += write(1, " ", 1);
				if (sign)
					result += write(1, "-", 1);
				for (int idx = 0 ; idx < pre - ft_numlen(num, 10) ; idx++)
					result += write(1, "0", 1);
				if (num != 0 || !dot || pre != 0)
					ft_putnbr(num, 10);
			}

			else if (fmt[i] == 'x')
			{
				long long num = va_arg(ap, int);
				if (num < 0)
				{
					sign = 1;
					num *= -1;
				}
				if (num == 0 && dot && pre == 0)
					width++;
				for (int idx = 0 ; idx < width - sign - max(pre, ft_numlen(num, 16)) ; idx++)
					result += write(1, " ", 1);
				if (sign)
					result += write(1, "-", 1);
				for (int idx = 0 ; idx < pre - ft_numlen(num, 16) ; idx++)
					result += write(1, "0", 1);
				if (num != 0 || !dot || pre != 0)
					ft_putnbr(num, 16);
			}

			else
				i--;
		}

		else
			result += write(1, &fmt[i], 1);
		i++;
	}
	return (result);
}
