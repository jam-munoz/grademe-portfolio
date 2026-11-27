#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <unistd.h>

#define BUF_SIZE 1024

typedef struct
{
	va_list		ap;
	const char	*format;
	char		buf[BUF_SIZE];
	int			buf_len;
	int			count;
}	t_printf;

bool print_buf(t_printf *pf)
{
	if (write(STDOUT_FILENO, pf->buf, pf->buf_len) == -1)
		return true;
	pf->count += pf->buf_len;
	pf->buf_len = 0;
	return false;
}

int	digit_count(unsigned int n)
{
	if (n < 10)
		return (1);
	if (n < 100)
		return (2);
	if (n < 1000)
		return (3);
	if (n < 10000)
		return (4);
	if (n < 100000)
		return (5);
	if (n < 1000000)
		return (6);
	if (n < 10000000)
		return (7);
	if (n < 100000000)
		return (8);
	if (n < 1000000000)
		return (9);
	return (10);
}

int	hex_digit_count(unsigned long n)
{
	int	digits;

	digits = 0;
	while (n > 0)
	{
		n >>= 4;
		digits++;
	}
	return (digits);
}

bool print_zero(int n, t_printf *pf)
{
	if (n == 0)
	{
		pf->buf[pf->buf_len++] = '0';
		return true;
	}
	else
		return false;
}

bool convert_int(t_printf *pf)
{
	int nb = va_arg(pf->ap, int);
	unsigned int n = nb;

	if (print_zero(nb, pf))
		return false;
	if (nb < 0)
	{
		n = -n;
		pf->buf[pf->buf_len++] = '-';
	}
	int digits = digit_count(n);
	if (pf->buf_len + digits > BUF_SIZE)
	{
		if (print_buf(pf))
			return true;
	}
	pf->buf_len += digits;
	digits = pf->buf_len;
	while (n > 0)
	{
		pf->buf[--digits] = (n % 10) + '0';
		n /= 10;
	}
	return false;
}

bool convert_string(t_printf *pf)
{
	char	*str = va_arg(pf->ap, char *);

	if (!str)
		str = "(null)";
	while (*str)
	{
		pf->buf[pf->buf_len++] = *str;
		str++;
		if (pf->buf_len == BUF_SIZE)
		{
			if (print_buf(pf))
				return true;
		}
	}
	return false;
}

bool convert_hex(t_printf *pf)
{
	unsigned int n = va_arg(pf->ap, int);
	if (print_zero(n, pf))
		return false;
	static const char hex_str[] = "0123456789abcdef";
	int digits = hex_digit_count(n);
	if (pf->buf_len + digits > BUF_SIZE)
	{
		if (print_buf(pf))
			return true;
	}
	pf->buf_len += digits;
	digits = pf->buf_len;
	while (n > 0)
	{
		pf->buf[--digits] = hex_str[n & 0xF];
		n >>= 4;
	}
	return false;
}

bool pf_conversion(t_printf *pf)
{
	pf->format++;
	if (*pf->format == 'd')
	{
		if (convert_int(pf))
			return true;
	}
	else if (*pf->format == 's')
	{
		if (convert_string(pf))
			return true;
	}
	else if (*pf->format == 'c')
		pf->buf[pf->buf_len++] = (char)va_arg(pf->ap, int);
	else if (*pf->format == 'x')
	{
		if (convert_hex(pf))
			return true;
	}
	else if (*pf->format == '%')
		pf->buf[pf->buf_len++] = '%';
	else
	{
		pf->buf[pf->buf_len++] = '%';
		if (pf->buf_len == BUF_SIZE)
		{
			if (print_buf(pf))
				return true;
		}
		pf->buf[pf->buf_len++] = *pf->format;
	}
	return false;
}

int	mini_printf(const char *format, ...)
{
	t_printf pf;

	pf.format = format;
	pf.buf_len = 0;
	pf.count = 0;
	va_start(pf.ap, format);

	for (; *pf.format; pf.format++)
	{
		if (*pf.format == '%')
		{
			if (pf_conversion(&pf))
				return -1;
		}
		else
			pf.buf[pf.buf_len++] = *pf.format;
		if (pf.buf_len == BUF_SIZE)
		{
			if (print_buf(&pf))
				return -1;
		}
	}
	if (pf.buf_len > 0)
	{
		if (print_buf(&pf))
			return -1;
	}
	va_end(pf.ap);
	return pf.count;
}