#include <stdbool.h>

bool forbidden(char c, const char *allowed)
{
	for (int i = 0; allowed[i]; i++)
	{
		if (c == allowed[i])
			return false;
	}
	return true;
}

unsigned int prefix_span(const char *text, const char *allowed)
{
	unsigned int i = 0;
	for (; text[i]; i++)
	{
		if (forbidden(text[i], allowed))
			break;
	}
	return (i);
}
