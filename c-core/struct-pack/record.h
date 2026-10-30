#ifndef RECORD_H
# define RECORD_H

// The four fields are fixed. Their order is yours and it sets sizeof(record).
typedef struct s_record
{
	long		stamp;
	int		id;
	short		code;
	unsigned char	flag;
}	record;

void		record_set(record *dst, long stamp, int id, short code,
			unsigned char flag);
long		record_stamp(const record *src);
int		record_id(const record *src);
short		record_code(const record *src);
unsigned char	record_flag(const record *src);

#endif
