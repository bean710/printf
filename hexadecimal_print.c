#include "holberton.h"
#include <stdio.h>

int dec_to_hex(unsigned int i)
{
	int count = 1;
	char digs[] = "0123456789abcdef";
	if (i > 15)
		count += dec_to_hex(i / 16);

	_putchar(digs[i % 16]);

	return (count);
}

int print_hex(void *uhp)
{
	unsigned int i = 1, count = 0;
	unsigned int hex = *(unsigned int *)uhp;

	return(dec_to_hex(hex));
}
