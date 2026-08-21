int	hidden_extension_at(const char *name)
{
	int i = 0;
	for (; name[i]; i++)
		;
	while (name[i] != '.' && i > 0)
		i--;
	if (i > 0)
		i--;
	while (name[i] != '.' && i > 0)
		i--;
	if (name[i] != '.')
		return -1;
	return i;
}
