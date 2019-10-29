#include "holberton.h"

/**
 * base_converter - Converts an unsigned integer to a different base and
 * prints the result
 * @i: The unsigned integer to be converted and printed
 * @base: The base to be converted to
 * @set: The set of characters to be used for base conversion. i.e.
 * "0123456789abcdef" for hexadecimal
 *
 * Return: The number of characters printed
 */
int base_converter(unsigned int i, unsigned int base, char *set)
{
	int count = 1;

	if (i > base - 1)
		count += base_converter(i / base, base, set);

	_putchar(set[i % base]);

	return (count);
}

/**
 * print_hex - Prints an unsigned integer as a hexidecimal
 * @uhp: Void pointer to an adress in memory which holds an unsigned integer
 * @params: a structure containing info about the argument
 * Return: The number of characters printed
 */
int print_hex(void *uhp, param params)
{
	unsigned int hex = *(unsigned int *)uhp;
	char *set = "0123456789abcdef";
	int count = 0;

	if (params.pound)
	{
		_putchar('0');
		_putchar('x');
		count += 2;
	}

	return (base_converter(hex, 16, set) + count);
}

/**
 * print_hex_u - Prints an unsigned integer as a hexidecimal in uppercase
 * format
 * @uhp: Void pointer to an adress in memory which holds an unsigned integer
 * @params: a structure containing info about the argument
 * Return: The number of characters printed
 */
int print_hex_u(void *uhp, param params)
{
	unsigned int hex = *(unsigned int *)uhp;
	char *set = "0123456789ABCDEF";
	int count = 0;

	if (params.pound)
	{
		_putchar('0');
		_putchar('X');
		count += 2;
	}

	return (base_converter(hex, 16, set) + count);
}
