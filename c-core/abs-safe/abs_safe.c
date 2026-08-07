long	abs_safe(int n)
{
	long nb = n;
	return nb * ((nb >> 31) | 1);
}