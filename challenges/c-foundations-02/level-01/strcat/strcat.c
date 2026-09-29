char	*gm_strcat(char *dst, const char *src)
{
	int i;
	char *p = dst;
	while (*p)
	{
		p++;
	}
	for (i = 0; src[i]; i++)
	{
		p[i] = src[i];
	}
	p[i] = '\0';
	return dst;
}
