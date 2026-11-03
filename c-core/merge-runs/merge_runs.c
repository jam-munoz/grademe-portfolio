#include <stddef.h>

// out receives the ln + rn values of left and right merged in ascending order.
// Both runs arrive sorted; when the two fronts are equal, left goes first.
void	merge_runs(const int *left, size_t ln, const int *right, size_t rn, int *out)
{
	int size = ln + rn;
	for (int i = 0, l = 0, r = 0; i < size; i++)
	{
		if (r >= (int)rn || (l < (int)ln && left[l] <= right[r]))
			out[i] = left[l++];
		else
			out[i] = right[r++];
	}
}
