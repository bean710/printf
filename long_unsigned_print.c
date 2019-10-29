#include "holberton.h"

/**
 * print_unsig_long - Prints an unsigned long integer
 * @uip: Void opinter to an address in memory which holds an unsigned long
 * integer.
 * Return: The number of characters printed.
 */
int print_unsig_long(void *luip, param params)
{
	unsigned long int i = *(unsigned int *)luip;

	return (long_base_converter(i, 10, "0123456789"));
}
