int max(int *tab, unsigned int len)
{
	if (len == 0)
		return 0;
	
	int p = tab[0];
	for (unsigned int i = 1; i < len; i++)
		if (p < tab[i])
			p = tab[i];
	return p;
}