#include "holberton.h"

/**
 * long_base_converter - Converts a long unsigned integer to a different base
 * and prints the result.
 * @i: the long unsigned integer to be converted and printed.
 * @base: the base to be converted to.
 * @set: The set of characters to be used for base conversion. ie
 * "0123456789abcdef" for hexadecimal.
 * Return: the number of characters printed.
 */
int long_base_converter(unsigned long int i, unsigned long int base, char *set)
{
	int count = 1;

	if (i > base - 1)
		count += long_base_converter(i / base, base, set);

	_putchar(set[i % base]);

	return (count);
}

/**
 * print_long_hex - Prints a long unsigned integer as a hexadecimal.
 * @luhp: Void pointer to an address in memory which holds an unsigned integer.
 * Return: the number of characters printed.
 */
int print_long_hex(void *luhp, param params)
{
	unsigned long int hex = *(unsigned long int *)luhp;
	char *set = "0123456789abcdef";

	return (long_base_converter(hex, 16, set));
}

/**
 * print_long_hex_u - Prints a long unsigned integer as a hexadecimal in
 * uppercase format.
 * @luhp: Void pointer to an address in memory which holds a long unsigned int.
 * Return: the number of characters printed.
 */
int print_long_hex_u(void *luhp, param params)
{
	unsigned long int hex = *(unsigned long int *)luhp;
	char *set = "0123456789abcdef";

	return (long_base_converter(hex, 16, set));
}
