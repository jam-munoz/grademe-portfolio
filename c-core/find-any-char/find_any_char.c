char *find_any_char(const char *text, const char *needles)
{
	if (needles == (void *)0)
		return (void *)0;
	for (int i = 0; text[i]; i++)
	{
		for (int j = 0; needles[j]; j++)
		{
			if (text[i] == needles[j])
				return (char *)text + i;
		}
	}
	return (void *)0;
}
