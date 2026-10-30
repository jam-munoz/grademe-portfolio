#ifndef FLAGS_H
#define FLAGS_H

#define FLAG(bit) (1 << (bit))
#define HAS_FLAG(value, bit) (((1 << (bit)) & (value)) ? 1 : 0)
#define SET_FLAG(value, bit) ((value) | (1 << (bit)))
#define CLEAR_FLAG(value, bit) ((value) & ~(1 << (bit)))

unsigned int	update_flag(unsigned int value, unsigned int bit, int enabled);

#endif
