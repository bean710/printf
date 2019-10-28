#include "holberton.h"

/**
 * print_unint - Prints an unsigned integer
 * @uip: Void pointer to an adress in memory which holds an unsigned integer
 *
 * Return: The number of characters printed
 */
int print_unint(void *uip)
{
	unsigned int i = *(unsigned int *)uip;

	return (base_converter(i, 10, "0123456789"));
}
