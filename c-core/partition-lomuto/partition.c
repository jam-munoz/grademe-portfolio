#include <stddef.h>

void	swap(int *a, int *b);
// Lomuto partition of a[lo..hi] around the pivot a[hi], equal values to the
// left. Returns the index the pivot lands on.
size_t	partition(int *a, size_t lo, size_t hi)
{
	unsigned int i = lo;
	for (unsigned int j = i; j < hi; j++)
	{
		if (a[j] <= a[hi])
		{
			swap(&a[i], &a[j]);
			i++;
		}
	}
	swap(&a[i], &a[hi]);
	return i;
}

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
