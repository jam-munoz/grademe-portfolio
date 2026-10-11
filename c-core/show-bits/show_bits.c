#include <unistd.h>

void show_bits(unsigned char byte)
{
	char bits[9];
	for (int i = 7; i >= 0; i--)
	{
		bits[i] = (byte & 1) + '0';
		byte >>= 1;
	}
	bits[8] = '\0';
	write(STDOUT_FILENO, bits, 8);
}
