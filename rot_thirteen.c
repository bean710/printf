#include "holberton.h"
#include <stddef.h>

/**
 * print_rot - prints a string in ROT13 format.
 * @s: pointer to a string
 * @params: a structure containing info about the argument
 * Return: The number of characters printed.
 */
int print_rot(void *s, param params)
{
	int i, j;
	char *arr = *(char **)s;
	int count = 0, flag = 0;
	char check[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char rot[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

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
	for (i = 0; arr[i] != '\0'; i++, flag = 0)
	{
		for (j = 0; check[j] != '\0'; j++)
		{
			if (arr[i] == check[j])
			{
				_putchar(rot[j]);
				count++;
				flag = 1;
			}
		}
		if (flag < 1)
		{
			_putchar(arr[i]);
			count++;
		}
	}
	return (count);
}
