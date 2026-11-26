#include <stdbool.h>
#include <stdio.h>

bool next_perm(char *s, int n);

int main(int argc, char **argv)
{
	if (argc != 2)
		return 1;

	bool seen[256] = { 0 };

	for (int i = 0; argv[1][i]; i++)
	{
		seen[(unsigned char)argv[1][i]] = true;
	}
	char str[256];
	int size = 0;
	for (int i = 0; i < 256; i++)
	{
		if (seen[i])
		{
			str[size++] = (unsigned char)i;
		}
	}
	str[size] = '\0';

	do {
		puts(str);
	} while (next_perm(str, size));

	return 0;
}

bool next_perm(char *s, int n)
{
	int i = n - 2;
	while (i >= 0 && s[i] >= s[i + 1])
		i--;
	if (i < 0)
		return false;

	int j = n - 1;
	while (s[j] <= s[i])
		j--;

	char t = s[i]; s[i] = s[j]; s[j] = t;

	for (int a = i + 1, b = n - 1; a < b; a++, b--)
	{
		t = s[a]; s[a] = s[b]; s[b] = t;
	}
	return true;
}