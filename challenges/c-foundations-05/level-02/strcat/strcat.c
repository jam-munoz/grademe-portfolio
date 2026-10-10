char	*gm_strcat(char *dst, const char *src)
{
	char *p = dst;
	int i;

	while (*dst)
		dst++;
	for (i = 0; src[i]; i++)
		dst[i] = src[i];
	dst[i] = '\0';
	return p;
}
