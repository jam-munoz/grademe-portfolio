#include <stddef.h>

// out[i] holds the sum of the four integers on row i, and rows stays read-only.
// The width is fixed at 4 by the type of rows, so no parameter carries it.
void	row_sums(const int (*rows)[4], size_t nrows, int *out)
{
	for (size_t i = 0; i < nrows; i++)
	{
		out[i] = 0;
		for (size_t j = 0; j < 4; j++)
		{
			out[i] += rows[i][j];
		}
	}
}
