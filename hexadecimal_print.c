#include "holberton.h"
#include <stdio.h>

int base_converter(unsigned int i, unsigned int base, char *set)
{
	int count = 1;

	if (i > base - 1)
		count += base_converter(i / base, base, set);

	_putchar(set[i % base]);

	return (count);
}

int print_hex(void *uhp)
{
	unsigned int i = 1, count = 0;
	unsigned int hex = *(unsigned int *)uhp;
	char *set = "0123456789abcdef";

	return (base_converter(hex, 16, set));
}

int print_hex_u(void *uhp)
{
	unsigned int i = 1, count = 0;
	unsigned int hex = *(unsigned int *)uhp;
	char *set = "0123456789ABCDEF";

	return (base_converter(hex, 16, set));
}
