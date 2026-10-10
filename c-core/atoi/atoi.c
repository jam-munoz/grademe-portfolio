#include <stdbool.h>

bool	ft_isspace(char c);
bool	ft_isdigit(int c);

int gm_atoi(const char *str)
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
	while (ft_isdigit(*str))
	{
		sum = (sum * 10) + (*str - '0');
		str++;
	}
	return sign * sum;
}

bool	ft_isspace(char c)
{
	return (c == ' ' || (9 <= c && c <= 13));
}

bool	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}