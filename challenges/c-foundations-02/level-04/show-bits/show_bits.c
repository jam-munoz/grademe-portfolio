#include <unistd.h>

void	ft_putchar(char c);

void show_bits(unsigned char byte)
{
    int bits = 128;
    for(int i = 0; i < 8; i++)
    {
        if (byte & bits)
        {
            ft_putchar('1');
        }
        else
            ft_putchar('0');
        bits >>= 1;
    }
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
