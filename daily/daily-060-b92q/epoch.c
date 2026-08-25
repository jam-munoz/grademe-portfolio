int	add_seconds(int now, int add)
{
	int sum = now + add;
	if (sum >= 0)
		return sum;
	else return -1;
}
