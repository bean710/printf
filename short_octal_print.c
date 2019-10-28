#include "holberton.h"
 
/**
 * print_oct_short - prints an unsigned short int as an octal.
 * @suop: Void pointer to an address in memory holding an unsigned short int.
 * Return: Number of characters printed.
 */
int print_oct_short(void *suop)
{
	unsigned short int oct = *(unsigned short int *)suop;

	return (short_base_conv(oct, 8, "01234567"));
}
