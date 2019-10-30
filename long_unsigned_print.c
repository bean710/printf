#include "holberton.h"

/**
 * print_unsig_long - Prints an unsigned long integer
 * @luip: Void pointer to an address in memory which holds an unsigned long
 * integer.
 * @params: a structure containing info about the argument
 * Return: The number of characters printed.
 */
int print_unsig_long(void *luip, param params)
{
	unsigned long int i = *(unsigned int *)luip;
	(void)(params);

	return (long_base_converter(i, 10, "0123456789"));
}
