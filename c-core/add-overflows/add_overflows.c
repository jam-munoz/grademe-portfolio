int	add_overflows(int a, int b)
{
	if ((b > 0 && a > 2147483647 - b) || (b < 0 && (a < -2147483647 - 1 - b)))
		return 1;
	else
		return 0;
}
