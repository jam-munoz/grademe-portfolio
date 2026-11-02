#include <stdbool.h>
// Return 1 if n is a prime number, 0 otherwise.
// n is between -1000 and 100000.
int	is_prime(int n)
{
	if (n < 2)
		return false;
	if (n < 4)
		return true;
	if (n % 2 == 0 || n % 3 == 0)
		return false;
	int i = 5;
	while (i * i <= n)
	{
		if (n % i == 0 || n % (i + 2) == 0)
			return false;
		i += 6;
	}
	return true;
}
