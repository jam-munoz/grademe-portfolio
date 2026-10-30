#include "record.h"

// record_set stores the four values in *dst; each accessor reads one back.
void	record_set(record *dst, long stamp, int id, short code, unsigned char flag)
{
	dst->stamp = stamp;
	dst->id = id;
	dst->code = code;
	dst->flag = flag;
}

long	record_stamp(const record *src)
{
	return src->stamp;
}

int	record_id(const record *src)
{
	return src->id;
}

short	record_code(const record *src)
{
	return src->code;
}

unsigned char	record_flag(const record *src)
{
	return src->flag;
}
