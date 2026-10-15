#include <stddef.h>

void	ft_swap(int *a, int *b);
// insertion_steps sorts the n integers at a in ascending order, in place,
// and calls report(a, n) once after each insertion. It prints nothing itself.
void	insertion_steps(int *a, size_t n, void (*report)(const int *, size_t))
{
	for (unsigned int i = 1; i < n; i++)
	{
		int key = a[i];
		for (int j = i - 1; key < a[j] && j >= 0; j--)
		{
			ft_swap(&a[j], &a[j + 1]);
		}
		report(a, n);
	}
}

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
