#include "holberton.h"

/**
 * print_unsig_long - Prints an unsigned long integer
 * @luip: Void pointer to an address in memory which holds an unsigned long
 * integer.
 * @params: a structure containing info about the argument
 * Return: The number of characters printed.
 */
int print_unsig_long(va_list valist, param params)
{
	unsigned long int i = va_arg(valist, unsigned long int);
	(void)(params);

	return (long_base_converter(i, 10, "0123456789"));
}
