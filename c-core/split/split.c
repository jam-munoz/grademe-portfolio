#include <stdbool.h>
#include <stdlib.h>

int	ft_strlen(const char *str)
{
	const char	*p;

	p = str;
	while (*p != '\0')
		p++;
	return (p - str);
}

bool is_sep(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return true;
		charset++;
	}
	return false;
}

int word_count(char *str, char *charset)
{
	int count = 0;
	int len = ft_strlen(str);
	for (int i = 0; i < len; i++)
	{
		if (!is_sep(str[i], charset))
		{
			count++;
			while (str[i] && !is_sep(str[i], charset))
			{
				i++;
			}
		}
	}
	return count;
}

char *word_split(char *str, char *charset)
{
	int len = 0;
	while (str[len] && !is_sep(str[len], charset))
		len++;
	char *out = malloc((len + 1) * sizeof(char));
	for (int i = 0; i < len; i++)
	{
		out[i] = str[i];
	}
	return out;
}

char **split(char *str, char *charset)
{
	int words = word_count(str, charset);
	char **arr = malloc((words + 1) * sizeof(char *));
	for (int i = 0; i < words; i++)
	{
		while (is_sep(*str, charset))
			str++;
		arr[i] = word_split(str, charset);
		while (*str && !is_sep(*str, charset))
			str++;
	}
	return arr;
}
