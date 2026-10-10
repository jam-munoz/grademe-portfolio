#include <stdbool.h>
#include <unistd.h>

bool	ft_isprint(int c);

void	*hex_dump(void *addr, unsigned int size)
{
	if (size == 0)
		return (addr);
	unsigned char *p = addr;
	char str[8192];
	char hex_digits[] = "0123456789abcdef";
	int	len, j;
	int pos = 0;

	for (unsigned int i = 0; i < size; i += len)
	{
		len = size - i;
		if (len > 16)
			len = 16;
		for (j = 0; j < len; j++)
		{
			str[pos++] = hex_digits[p[i + j] >> 4];
			str[pos++] = hex_digits[p[i + j] & 0xF];
			str[pos++] = ' ';
		}
		for (; j < 16; j++)
		{
			str[pos++] = ' ';
			str[pos++] = ' ';
			str[pos++] = ' ';
		}
		str[pos++] = ' ';
		for (j = 0; j < len; j++)
		{
			if (ft_isprint(p[i + j]))
				str[pos++] = p[i + j];
			else
				str[pos++] = '.';
		}
		str[pos++] = '\n';
	}
	write(STDOUT_FILENO, str, pos);
	return (addr);
}

bool	ft_isprint(int c)
{
	return (' ' <= c && c <= '~');
}
