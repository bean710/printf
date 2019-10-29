#include "holberton.h"

/**
 * short_base_conv - Converts a unsigned short integer to a different base
 * and prints the result.
 * @i: the unsigned short integer to be converted and printed.
 * @base: the base to be converted to.
 * @set: The set of characters to be used for base conversion. ie
 * "0123456789abcdef" for hexadecimal.
 * Return: the number of characters printed.
 */
int short_base_conv(unsigned short int i, unsigned short int base, char *set)
{
	int count = 1;

	if (i > base - 1)
		count += short_base_conv(i / base, base, set);

	_putchar(set[i % base]);

	return (count);
}

/**
 * print_short_hex - Prints a long unsigned integer as a hexadecimal.
 * @suhp: Void pointer to an address in memory which holds an unsigned integer.
 * @params: a structure containing info about the argument
 * Return: the number of characters printed.
 */
int print_short_hex(void *suhp, param params)
{
	unsigned short int hex = *(unsigned short int *)suhp;
	char *set = "0123456789abcdef";
	int count = 0;

	if (params.pound)
	{
		count += _putchar('0');
		count += _putchar('x');
	}

	return (short_base_conv(hex, 16, set) + count);
}

/**
 * print_short_hex_u - Prints a long unsigned integer as a hexadecimal in
 * uppercase format.
 * @suhp: Void pointer to an address in memory which holds a long unsigned int.
 * @params: a structure containing info about the argument
 * Return: the number of characters printed.
 */
int print_short_hex_u(void *suhp, param params)
{
	unsigned short int hex = *(unsigned short int *)suhp;
	char *set = "0123456789abcdef";
	int count = 0;

	if (params.pound)
	{
		count += _putchar('0');
		count += _putchar('X');
	}


	return (short_base_conv(hex, 16, set) + count);
}
