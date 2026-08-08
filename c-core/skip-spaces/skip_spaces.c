// Return the address of the first character of s that is not a space or a tab.
// Only the leading run is skipped, and the buffer is never written to.
int isspace(char c);

const char	*skip_spaces(const char *s)
{
	int i = 0;
	for (; s[i]; i++)
		if (!isspace(s[i]))
			break;
	return &s[i];
}

int isspace(char c)
{
	return (c == ' ' || c == '\t');
}