#include "holberton.h"

/**
 * print_unsigned_long_decimal - prints an unsigned long int in base 10.
 * @ulivp: void pointer to a unsigned long int.
 * @params: a structure containing info about the argument
 * Return: the number of characters printed.
 */
int print_unsigned_long_decimal(void *ulivp, param params)
{
	int uli = *(unsigned long int *)ulivp;
	int count = 0;

	return (long_base_converter(uli, 10, "0123456789") + count);
}
