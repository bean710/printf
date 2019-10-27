#include "holberton.h"

/**
 * print_binary - Prints a number in binary.
 * @ip: A pointer to an unsigned int
 * Return: the number of characters printed.
 */
int print_binary(void *ip)
{
	unsigned int n = *(unsigned int *)ip;
	int i;
	int count = 0;

	for (i = 31; i >= 0; i--)
	{
		if (n / _pow(2, i) > 0 && count == 0)
		{
			_putchar('1');
			count++;
			n -= _pow(2, i);
		}
		if (count > 0)
		{

			if (n / _pow(2, i) > 0)
			{
				_putchar('1');
				n -= _pow(2, i);
				count++;
			}
			else if (n / _pow(2, i) == 0)
			{
				_putchar('0');
				count++;
			}
		}
	}
	return (count);
}
