#include "holberton.h"
#include <stdio.h>

/**
 * print_long_decimal - prints a long int
 * @ip: Pointer to a long int
 * @params: a structure containing info about the argument
 * Return: the number of chars printed.
 */
int print_long_decimal(void *ip, param params)
{
	long int decimal = *(long int *)ip;
	int count = 0;

	if (params.plus && decimal > -1)
		count += _putchar('+');
	else if (params.space && decimal > -1)
		count += _putchar(' ');

	print_long_number(decimal);

	return (getlen_long(decimal) + count + (decimal < 0 ? 1 : 0));
}

/**
 * print_long_number - prints a long number
 * @n: number to print
 */
void print_long_number(long int n)
{
	long int i;

	if (n < 0)
	{
		_putchar('-');
		for (i = 0; i < getlen_long(n); i++)
			_putchar('0' + -getnum_long(n, i));
	}
	else
	{
		for (i = 0; i < getlen_long(n); i++)
			_putchar('0' + getnum_long(n, i));
	}
}

/**
 * _pow_long - Calculates exponents
 * @a: base
 * @b: exponent
 *
 * Return: a^b
 */
long int _pow_long(int a, int b)
{
	int i, ans;

	if (b <= 0)
		return (1);

	ans = a;
	for (i = 0; i < b - 1; i++)
	{
		ans *= a;
	}

	return (ans);
}

/**
 * getnum_long - gets the 'index'th digit of num, starting from the left at 0
 * @num: the number to extract digit from
 * @index: the index of the desired digit with 0 being the leftmost digit
 *
 * Return: The 'index'th digit of num
 */
long int getnum_long(long int num, long int index)
{
	long int l;

	l = getlen_long(num);
	num = num / _pow_long(10, l - 1 - index);
	return (num % 10);
}

/**
 * getlen_long - gets the length of the number num
 * @num: the number to get length of
 *
 * Return: length of number 'num'
 */
long int getlen_long(long int num)
{
	long int i;

	i = 1;
	while (num > 9 || num < -9)
	{
		i++;
		num /= 10;
	}
	return (i);
}
