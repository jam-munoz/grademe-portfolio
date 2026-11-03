#include "flags.h"

unsigned int	update_flag(unsigned int value, unsigned int bit, int enabled)
{
	if (enabled)
		return SET_FLAG(value, bit);
	else
		return CLEAR_FLAG(value, bit);
}
