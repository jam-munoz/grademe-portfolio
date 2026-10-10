#include <stdbool.h>
#include <stddef.h>

bool	ft_isspace(char c);
bool	ft_isdigit(int c);
bool	ft_islower(int c);
bool	valid_base(char c, int base);
long	parse_int_base(const char **str, int base);

long	gm_strtol(const char *str, char **endptr, int base)
{
	int sign = 1;
	if (endptr != NULL)
		*endptr = (char *)str;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (base == 0 || base == 16)
	{
		if (*str == '0')
		{
			str++;
			if (*str == 'x')
			{
				base = 16;
				str++;
			}
			else
				base = 8;
		}
		else
			base = 10;
	}
	long n = parse_int_base(&str, base);
	if (n == -1)
		return 0;
	*endptr = (char *)str;
	return n * sign;
}


bool	ft_isspace(char c)
{
	return (c == ' ' || (9 <= c && c <= 13));
}

bool	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

bool	ft_islower(int c)
{
	return ('a' <= c && c <= 'z');
}

long parse_int_base(const char **str, int base)
{
	long sum = 0;

	if (!valid_base(**str, base))
		return -1;

	while (valid_base(**str, base))
	{
		sum *= base;
		if (ft_isdigit(**str))
			sum += **str - '0';
		else if (ft_islower(**str))
			sum += **str - 'a' + 10;
		else
			sum += **str - 'A' + 10;
		*str = *str + 1;
	}
	return sum;
}

bool valid_base(char c, int base)
{
	if ('0' <= c && c <= '9')
	{
		if (c - '0' < base)
			return true;
	}
	else if ('a' <= c && c <= 'f')
	{
		if (c - 'a' + 10 < base)
			return true;
	}
	else if ('A' <= c && c <= 'F')
	{
		if (c - 'A' + 10 < base)
			return true;
	}
	return false;
}