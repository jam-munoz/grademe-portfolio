#include <stdbool.h>
#include <stdlib.h>

bool is_sep(char c, char *charset)
{
	for (int i = 0; charset[i]; i++)
	{
		if (c == charset[i])
			return true;
	}
	return false;
}

int word_count(char *str, char *charset)
{
	int words = 0;

	for (int i = 0; str[i]; )
	{
		if (!is_sep(str[i], charset))
		{
			words++;
			while (str[i] && !is_sep(str[i], charset))
				i++;
		}
		else
			i++;
	}
	return words;
}

char *word_split(char *str, char *charset)
{
	int len = 0;
	while (!is_sep(str[len], charset))
		len++;
	char *out = malloc((len + 1) * sizeof(char));
	if (out == NULL)
		return (NULL);
	for (int i = 0; i < len; i++)
	{
		out[i] = str[i];
	}
	out[len] = '\0';
	return out;
}

char **split(char *str, char *charset)
{
	int words = word_count(str, charset);
	char **out = malloc((words + 1) * sizeof(char *));
	if (out == NULL)
		return (NULL);
	for (int i = 0, j = 0; i < words; i++)
	{
		while (str[j] && is_sep(str[j], charset))
			j++;
		out[i] = word_split(str + j, charset);
		while (str[j] && !is_sep(str[j], charset))
			j++;
	}
	out[words] = NULL;
	return out;
}
