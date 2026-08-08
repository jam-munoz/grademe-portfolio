// Return 1 when value can be stored in an int without changing,
// 0 when the conversion would lose information.
int	fits_in_int(long value)
{
	return (-2147483648 <= value && value <= 2147483647);
}
