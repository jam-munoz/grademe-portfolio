#include <unistd.h>

// Print n in decimal on standard output, with no newline.
// n is between 0 and INT_MAX.
void	put_number(int nb)
{
	char str[11];
	unsigned int n = nb;
	int i = 10;
	if (nb < 0)
		n = -n;
	if (nb == 0)
		str[i--] = '0';
	while (n > 0)
	{
		str[i--] = n % 10 + '0';
		n /= 10;
	}
	if (nb < 0)
	{
		str[i--] = '-';
	}
	i++;
	write(STDOUT_FILENO, str + i, 11 - i);
}
