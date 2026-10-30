#include "meter.h"
#include <stdlib.h>

struct s_meter
{
	int	value;
};

meter	*meter_create(int initial)
{
	meter *p;
	
	p = malloc(sizeof(meter));
	p->value = initial;
	return p;
}

void	meter_destroy(meter *item)
{
	free(item);
	item = NULL;
}

void	meter_add(meter *item, int amount)
{
	item->value += amount;
}

int	meter_value(const meter *item)
{
	return item->value;
}
