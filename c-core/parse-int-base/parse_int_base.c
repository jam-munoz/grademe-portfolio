#include <stdbool.h>

bool	ft_isspace(char c);
bool	ft_isdigit(int c);
bool	ft_islower(int c);
bool	valid_base(char c, int base);

int parse_int_base(const char *str, int base)
{
	int sum = 0;
	int sign = 1;

	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (valid_base(*str, base))
	{
		sum *= base;
		if (ft_isdigit(*str))
			sum += *str - '0';
		else if (ft_islower(*str))
			sum += *str - 'a' + 10;
		else
			sum += *str - 'A' + 10;
		str++;
	}
	return sum * sign;
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