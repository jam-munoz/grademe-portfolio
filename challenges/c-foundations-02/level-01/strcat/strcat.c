char	*strcat(char *dst, const char *src)
{
	int i, j;
	if (!src)
		return (dst);
	for (i = 0; dst[i]; i++) ;
	for (j = 0; src[j]; i++, j++)
	{
		dst[i] = src[j];
	}
	dst[i] = '\0';
	return (dst);
}
