#include <stddef.h>

void	ft_swap(int *a, int *b);
// Flip the order of the first n elements of a, in place.
// Nothing past that prefix moves, and n == 0 changes nothing.
void	reverse_int(int *a, size_t n)
{
	for (size_t i = 0; i < n; i++, n--)
		ft_swap(&a[i], &a[n - 1]);
}

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}