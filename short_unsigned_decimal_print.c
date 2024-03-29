#include "holberton.h"

/**
 * print_unsigned_short_decimal - prints an unsigned short int in base 10.
 * @usivp: void pointer to mallocd mem containing an unsigned short int.
 * @params: a structure containing info about the argument
 * Return: the number of characters printed.
 */
int print_unsigned_short_decimal(void *usivp, param params)
{
	unsigned short int usi = *(unsigned short int *)usivp;
	(void)(params);

	return (short_base_conv(usi, 10, "0123456789"));
}
