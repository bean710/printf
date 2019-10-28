#include "holberton.h"
#include <stddef.h>

/**
 * print_reverse - prints a string in reverse.
 * @s: a void pointer to a string
 * Return: the number of characters
 */
int print_reverse(void *s)
{
	char *arr = *(char **)s;
	int i = 0;
	int count = 0;

	if (arr == NULL)
	{
		_putchar('(');
		_putchar('n');
		_putchar('u');
		_putchar('l');
		_putchar('l');
		_putchar(')');
		return (6);
	}
	for (i = 0; arr[i] != '\0'; i++)
		;
	i--;
	for (; i > -1; i--)
	{
		_putchar(arr[i]);
		count++;
	}
	return (count);
}
