#include "holberton.h"

/**
 * print_unsig_short - Prints an unsigned short integer in base 10.
 * @suip: Void opinter to an address in memory which holds an unsigned short
 * integer.
 * @params: a structure containing info about the argument
 * Return: The number of characters printed.
 */
int print_unsig_short(va_list valist, param params)
{
	unsigned short int i = va_arg(valist, int);
	(void)(params);

	return (short_base_conv(i, 10, "0123456789"));
}
