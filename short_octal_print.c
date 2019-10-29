#include "holberton.h"

/**
 * print_oct_short - prints an unsigned short int as an octal.
 * @suop: Void pointer to an address in memory holding an unsigned short int.
 * @params: a structure containing info about the argument
 * Return: Number of characters printed.
 */
int print_oct_short(void *suop, param params)
{
	unsigned short int oct = *(unsigned short int *)suop;
	int count = 0;

	if (params.pound)
		count += _putchar('0');

	return (short_base_conv(oct, 8, "01234567") + count);
}
