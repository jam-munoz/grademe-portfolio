#include <stddef.h>

// Return 1 when a[0..n - 1] never decreases, 0 at the first drop.
// Equal neighbours keep the answer 1. n of 0 or 1 is sorted by convention.
int	is_sorted(const int *a, size_t n)
{
	if (n < 2)
		return 1;
	n--;
	for (unsigned int i = 0; i < n; i++)
	{
		if (a[i] > a[i + 1])
			return 0;
	}
	return 1;
}
