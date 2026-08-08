int	safe_div(int a, int b, int *out)
{
	if (b == 0 || (a == -2147483647 - 1 && b == -1))
		return (-1);
	*out = a / b;
	return (0);
}
