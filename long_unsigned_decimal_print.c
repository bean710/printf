#include "holberton.h"

/**
 * print_unsigned_long_decimal - prints an unsigned long int in base 10.
 * @ulivp: void pointer to a unsigned long int.
 * @params: a structure containing info about the argument
 * Return: the number of characters printed.
 */
int print_unsigned_long_decimal(va_list valist, param params)
{
	unsigned long int uli = va_arg(valist, unsigned long int);
	int count = 0;
	(void)(params);

	return (long_base_converter(uli, 10, "0123456789") + count);
}
