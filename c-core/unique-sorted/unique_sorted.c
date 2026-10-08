#include <stddef.h>
// The input is already sorted, so equal values are neighbours.
// Pack the distinct ones into a[0..ret - 1] and return how many there are.
size_t	unique_sorted(int *a, size_t n)
{
	if (n == 0)
		return 0;
	int count = 1;
	for (size_t i = 1; i < n; i++)
	{
		if (a[count - 1] != a[i])
		{
			a[count] = a[i];
			count++;
		}
	}
	return count;
}
