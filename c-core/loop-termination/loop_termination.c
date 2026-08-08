#include <stddef.h>

// One step replaces the running value with half of it, until the value is 0.
// This version compiles clean and never arrives: fix the update.
size_t	count_steps(unsigned int start)
{
	long	value;
	size_t			steps;

	value = start;
	steps = 0;
	while (value > 0)
	{
		steps++;
		value = value / 2;
	}
	return (steps);
}
