int	message_length(const int *block, int len)
{
	int i;
	if (*block != 2)
		return -1;
	for (i = 1; block[i] != 0 && i < len; i++)
		;
	if (i < 9)
		return -1;
	i++;
	if (i > len)
		return -1;
	return len - i;
}
