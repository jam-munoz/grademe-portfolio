// Compare a and b as plain numbers, not the way C would compare them.
// Return -1 if a is smaller, 0 if both mean the same number, 1 if a is larger.
int	cmp_mixed(int a, unsigned int b)
{
	long x = a;
	long y = b;
	if (x < y)
		return -1;
	else if (x > y)
		return 1;
	else
		return 0;
}
