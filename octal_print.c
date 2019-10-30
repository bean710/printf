#include "holberton.h"

/**
 * print_oct - Prints an unsigned int as an octal
 * @uop: Void pointer to an adress in memory holding an unsigned int
 * @params: a structure containing info about the argument
 * Return: Number of characters printed
 */
int print_oct(void *uop, param params)
{
	unsigned int oct = *(unsigned int *)uop;
	int count = 0;

	if (params.pound && oct != 0)
		count += _putchar('0');

	return (base_converter(oct, 8, "01234567") + count);
}
