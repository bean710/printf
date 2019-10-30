#include "holberton.h"
#include <stdio.h>

/**
 * print_special - Prints a string and prints non-printable characters as
 * their ASCII value
 * @ssp: Void pointer to an adress where a pointer to the first character in
 * the string to be printed is stored
 * @params: a structure containing info about the argument
 * Return: Number of characters printed
 */
int print_special(void *ssp, param params)
{
	unsigned char *s = *(unsigned char **)ssp;
	char *hex = "0123456789ABCDEF";
	int count = 0;
	(void)(params);

	for (; *s; s++)
	{
		printf("\nChar: %c\n", *s);
		if (*s >= 32 && *s < 127)
		{
			_putchar(*s);
			count++;
		}
		else
		{
			_putchar('\\');
			_putchar('x');
			_putchar(hex[*s / 16]);
			_putchar(hex[*s % 16]);
			count += 4;
		}
	}

	return (count);
}
