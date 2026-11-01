unsigned char swap_bits(unsigned char byte)
{
	unsigned char a = byte >> 4;
	unsigned char b = byte << 4;
	return (a | b);
}