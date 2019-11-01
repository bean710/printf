#include "holberton.h"
#include <stddef.h>
/**
 * print_string - prints a string
 * @sp: void pointer to a string
 * @params: A structure containing info about the argument description.
 * Return: The number of characters printed.
 */
int print_string(va_list valist, param params)
{
	char *s = va_arg(valist, char *);
	int i = 0;
	(void)(params);

	if (s == NULL)
	{
		_putchar('(');
		_putchar('n');
		_putchar('u');
		_putchar('l');
		_putchar('l');
		_putchar(')');
		return (6);
	}
	for (; *s; s++, i++)
		_putchar(*s);

	return (i);
}
