int gm_strcmp(const char *s1, const char *s2)
{
	for (int i = 0; s1[i] || s2[i]; i++)
	{
		if (s1[i] != s2[i])
			return (unsigned char)s1[i] - s2[i];
	}
	return 0;
}
