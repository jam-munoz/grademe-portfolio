#include <stddef.h>

// sort_cost sorts a in place, ascending, with selection sort, and returns the
// number of comparisons between two array elements that the sort performed.
void	swap(int *a, int *b);

unsigned long	sort_cost(int *a, size_t n)
{
	unsigned long count = 0;

	for (unsigned int i = 0; i < n; i++)
	{
		int *min = &a[i];
		for (unsigned int j = i + 1; j < n; j++, count++)
		{
			if (*min > a[j])
				min = &a[j];
		}
		swap(&a[i], min);
	}
	return count;
}

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
