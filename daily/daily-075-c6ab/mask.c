void	mask_pan(char *out, const char *pan, int n)
{
    for (int i = 0; i < n - 4; i++, out++, pan++)
    {        *out = '*';
    }
    for (int i = 0; i < 4; i++, out++, pan++)
    {
                *out = *pan;


    }
    *out = '\0';
}
