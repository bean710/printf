#include "holberton.h"
#include <stddef.h>

/**
 * print_ptr - Prints the address held by a pointer in hexadecimal.
 * @p: void pointer to a unsigned long int.
 * @params: a structure containing info about the argument
 * Return: the number of characters printed.
 */
int print_ptr(void *p, param params)
{
	char *set = "0123456789abcdef";
	unsigned long int ptr_ul = *(unsigned long int *)p;
	int count = 0;

	if (ptr_ul == 0)
	{
		_putchar('(');
		_putchar('n');
		_putchar('i');
		_putchar('l');
		_putchar(')');
		return (5);
	}

	if (params.plus)
		count += _putchar('+');
	else if (params.space)
		count += _putchar(' ');

	_putchar('0');
	_putchar('x');
	return (2 + count + long_base_converter(ptr_ul, 16, set));
}
