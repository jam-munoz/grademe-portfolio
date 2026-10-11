unsigned char reverse_bits(unsigned char byte)
{
	unsigned char reverse = 0;
	unsigned char msb = 128;

	for (int i = 7; i > 0; i -= 2, msb >>= 1)
		reverse |= (byte << i) & msb;
	for (int i = 1; msb > 0; i += 2, msb >>= 1)
		reverse |= (byte >> i) & msb;
	return reverse;
}
