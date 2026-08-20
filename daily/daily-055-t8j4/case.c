void	lower_ascii(char *dst, const char *s)
{
    int i = 0;
    for (; s[i]; i++)
    {
        if ('A' <= s[i] && s[i] <= 'Z')
            dst[i] = s[i] + 32;
        else
            dst[i] = s[i];
    }
    dst[i] = '\0';
}
