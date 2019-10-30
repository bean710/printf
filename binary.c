#include "holberton.h"

/**
 * print_binary - Prints an unsigned number in binary.
 * @ip: A pointer to an unsigned int
 * @params: a structure containing info about the argument
 * Return: the number of characters printed.
 */
int print_binary(void *ip, param params)
{
	unsigned int n = *(unsigned int *)ip;
	unsigned int i;
	int count = 0;
	(void)(params);

	if (n == 0)
	{
		_putchar('0');
		return (1);
	}
	for (i = 31; i <= 31; i--)
	{
		if (n / u_pow(2, i) > 0 && count == 0)
		{
			_putchar('1');
			count++;
			n -= u_pow(2, i);
		}
		else if (count > 0)
		{

			if (n / u_pow(2, i) > 0)
			{
				_putchar('1');
				n -= u_pow(2, i);
				count++;
			}
			else if (n / u_pow(2, i) == 0)
			{
				_putchar('0');
				count++;
			}
		}
	}
	return (count);
}

/**
 * u_pow - Calculates exponents
 * @a: base
 * @b: exponent
 * Return: unsigned int of a^b
 */
unsigned int u_pow(unsigned int a, unsigned int b)
{
	unsigned int i, ans;

	if (b == 0)
		return (1);

	ans = a;
	for (i = 0; i < b - 1; i++)
	{
		ans *= a;
	}
	return (ans);
}
