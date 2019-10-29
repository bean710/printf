#include "holberton.h"
 
/**
 * print_oct_long - prints an unsigned long int as an octal.
 * @luop: Void pointer to an address in memory holding an unsigned long int.
 * Return: Number of characters printed.
 */
int print_oct_long(void *luop)
{
	unsigned long int oct = *(unsigned long int *)luop;

	return (long_base_converter(oct, 8, "01234567"));
}
