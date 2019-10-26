#include "holberton.h"

/**
 * print_string - prints a string
 * @sp: void pointer to a string
 * Return: The number of characters printed.
 */
int print_string(void *sp)
{
	char *s = *(char **)sp;
	int i = 0;

	for (; *s; s++, i++)
		_putchar(*s);

	return (i);
}
