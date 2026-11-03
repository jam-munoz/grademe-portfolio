#include <stddef.h>

// Exchanges the size bytes at a with the size bytes at b.
void	swap_bytes(void *a, void *b, size_t size)
{
	unsigned char *x = (unsigned char *)a;
	unsigned char *y = (unsigned char *)b;

	for (unsigned int i = 0; i < size; i++)
	{
		unsigned char temp = x[i];
		x[i] = y[i];
		y[i] = temp;
	}
}
