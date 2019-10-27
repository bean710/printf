#include "holberton.h"
#include <stdio.h>

int dec_to_hex(unsigned int i, char *set)
{
	int count = 1;
	if (i > 15)
		count += dec_to_hex(i / 16, set);

	_putchar(set[i % 16]);

	return (count);
}

int print_hex(void *uhp)
{
	unsigned int i = 1, count = 0;
	unsigned int hex = *(unsigned int *)uhp;
	char *set = "0123456789abcdef";

	return(dec_to_hex(hex, set));
}
