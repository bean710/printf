#include "holberton.h"

/**
 * print_unsig - Prints an unsigned integer
 * @uip: Void pointer to an adress in memory which holds an unsigned integer
 * @params: a structure containing info about the argument
 * Return: The number of characters printed
 */
int print_unsig(void *uip, param params)
{
	unsigned int i = *(unsigned int *)uip;
	(void)(params);

	return (base_converter(i, 10, "0123456789"));
}
