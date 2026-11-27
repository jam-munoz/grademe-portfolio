#include <limits.h>

int	fits_in_int(long value)
{
	if (value > INT_MAX || value < INT_MIN)
		return 0;
	return 1;
}
