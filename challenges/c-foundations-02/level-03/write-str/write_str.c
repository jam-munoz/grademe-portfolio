#include <unistd.h>

int	ft_strlen(char *str);

void write_str(char *str)
{
    write(1, str, ft_strlen(str));    
}


int	ft_strlen(char *str)
{
	char	*p;

	p = str;
	while (*p != '\0')
		p++;
	return (p - str);
}
