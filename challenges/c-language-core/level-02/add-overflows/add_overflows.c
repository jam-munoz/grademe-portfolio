int	add_overflows(int a, int b)
{
	return __builtin_add_overflow(a, b, &a);
}
