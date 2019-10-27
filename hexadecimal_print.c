#include "holberton.h"

int print_hex(void *uph)
{
	unsigned int i = 1, count = 0;
	unsigned int hex = *(unsigned int *)uhp;
	char hex_digs[] = "0123456789abcdef";

	if (hex == 0)
	{
		_putchar('0');
		return (1);
	}

	while (hex / (i * 16))
		i *= 16;

	while (i > 1)
	{
		_putchar(hex_digs[(hex % i)]);
		i /= 16;
	}
}

