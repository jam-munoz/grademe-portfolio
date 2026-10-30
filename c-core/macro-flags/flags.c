#include "flags.h"

unsigned int	update_flag(unsigned int value, unsigned int bit, int enabled)
{
	if (enabled)
		bit = SET_FLAG(value, bit);
	else
		bit = CLEAR_FLAG(value, bit);
	return bit;
}
