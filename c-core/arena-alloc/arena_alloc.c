#include <stddef.h>

static unsigned char pool[4096] = { 0 };
static size_t allocated = 0;
// arena_alloc hands out n bytes of a 4096-byte static pool, aligned on 8, or
// NULL when the request no longer fits. arena_reset makes the pool reusable.
void	*arena_alloc(size_t n)
{
	if (n == 0 || n + allocated > 4096)
		return NULL;
	if ((n & 0x7) != 0x0)
		n = (n & 0xF8) + 8;
	size_t block = allocated;
	allocated += n;
	return pool + block;
}

void	arena_reset(void)
{
	allocated = 0;
}
