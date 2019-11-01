#include "holberton.h"

/**
 * print_oct_long - prints an unsigned long int as an octal.
 * @luop: Void pointer to an address in memory holding an unsigned long int.
 * @params: a structure containing info about the argument
 * Return: Number of characters printed.
 */
int print_oct_long(va_list valist, param params)
{
	unsigned long int oct = va_arg(valist, unsigned long int);
	int count = 0;

	if (params.pound && oct != 0)
	{
		count += _putchar('0');
	}
	return (long_base_converter(oct, 8, "01234567") + count);
}
