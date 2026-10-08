char	*gm_strstr(const char *haystack, const char *needle)
{
	int j;
	if (*needle == '\0')
		return (char *)haystack;
	for (int i = 0; haystack[i]; i++)
	{
		if (haystack[i] == *needle)
		{
			for (j = 0; needle[j]; j++)
			{
				if (haystack[i + j] != needle[j])
					break;
			}
			if (needle[j] == '\0')
				return (char *)&haystack[i];
		}
	}
	return (void *)0;
}
