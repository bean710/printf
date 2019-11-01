#include "holberton.h"

/**
 * print_ptr - Prints the address held by a pointer in hexadecimal.
 * @p: void pointer to a unsigned long int.
 * @params: a structure containing info about the argument
 * Return: the number of characters printed.
 */
int print_ptr(va_list valist, param params)
{
	char *set = "0123456789abcdef";
	unsigned long int ptr_ul = va_arg(valist, unsigned long int);
	int count = 0;

	if (params.plus)
		count += _putchar('+');
	else if (params.space)
		count += _putchar(' ');

	_putchar('0');
	_putchar('x');
	return (2 + count + long_base_converter(ptr_ul, 16, set));
}
