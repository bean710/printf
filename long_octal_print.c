#include "holberton.h"

/**
 * print_oct_long - prints an unsigned long int as an octal.
 * @luop: Void pointer to an address in memory holding an unsigned long int.
 * @params: a structure containing info about the argument
 * Return: Number of characters printed.
 */
int print_oct_long(void *luop, param params)
{
	unsigned long int oct = *(unsigned long int *)luop;
	int count = 0;

	if (params.pound)
	{
		count += _putchar('0');
	}
	return (long_base_converter(oct, 8, "01234567") + count);
}
