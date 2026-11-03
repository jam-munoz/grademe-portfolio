// next_id returns 1 on its first call, then 2, 3, and so on. After reset_ids,
// the next call to next_id returns 1 again.
static unsigned int n = 0;

int	next_id(void)
{
	n++;
	return n;
}

void	reset_ids(void)
{
	n = 0;
}
