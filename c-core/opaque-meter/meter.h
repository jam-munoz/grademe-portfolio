#ifndef METER_H
#define METER_H

typedef struct s_meter	meter;

meter	*meter_create(int initial);
void	meter_destroy(meter *item);
void	meter_add(meter *item, int amount);
int 	meter_value(const meter *item);

#endif
