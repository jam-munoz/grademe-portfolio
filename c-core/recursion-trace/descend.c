#include <stddef.h>

// descend calls on_enter(n), recurses on n - 1, then calls on_leave(n).
// n <= 0 calls nothing at all, and a NULL callback is skipped, never called.
void	descend(int n, void (*on_enter)(int), void (*on_leave)(int))
{
	if (n < 1)
		return;
	if ((*on_enter) != NULL)
		on_enter(n);
	descend(n - 1, on_enter, on_leave);
	if ((*on_leave) != NULL)
	on_leave(n);
}
