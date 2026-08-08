#include <stddef.h>

// out[i] holds the sum of a[0] through a[i], and a stays read-only.
// The running total is a long because it can outgrow an int.
void	prefix_sum(const int *a, size_t n, long *out)
{
	if (n == 0)
		return;

	out[0] = a[0];

	for (size_t i = 1; i < n; i++)
		out[i] = a[i] + out[i - 1];
}
