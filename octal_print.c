#include "holberton.h"

/**
 * print_oct - Prints an unsigned int as an octal
 * @uop: Void pointer to an adress in memory holding an unsigned int
 *
 * Return: Number of characters printed
 */
int print_oct(void *uop, param params)
{
	unsigned int oct = *(unsigned int *)uop;
	int count = 0;

	if (params.pound)
		count += _putchar('0');

	return (base_converter(oct, 8, "01234567") + count);
}
