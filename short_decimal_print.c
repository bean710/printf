#include "holberton.h"
#include <stdio.h>

/**
 * print_decimal - prints an int
 * @ip: Pointer to an int
 * @params: a structure containing info about the argument
 * Return: the number of chars printed.
 */
int print_short_decimal(void *ip, param params)
{
	short int decimal = *(long int *)ip;
	int count = 0;

	if (params.plus && decimal > -1)
		count += _putchar('+');
	if (params.space && decimal > -1)
		count += _putchar(' ');

	print_short_number(decimal);

	return (getlen_short(decimal) + count + (decimal < 0 ? 1 : 0));
}

/**
 * print_number - prints a number
 * @n: number to print
 */
void print_short_number(long int n)
{
	short int i;

	if (n < 0)
	{
		_putchar('-');
		for (i = 0; i < getlen_short(n); i++)
			_putchar('0' + -getnum_short(n, i));
	}
	else
	{
		for (i = 0; i < getlen_short(n); i++)
			_putchar('0' + getnum_short(n, i));
	}
}

/**
 * _pow - Calculates exponents
 * @a: base
 * @b: exponent
 *
 * Return: a^b
 */
short int _pow_long(int a, int b)
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
 * getnum - gets the 'index'th digit of num, starting from the left at 0
 * @num: the number to extract digit from
 * @index: the index of the desired digit with 0 being the leftmost digit
 *
 * Return: The 'index'th digit of num
 */
int getnum_short(long int num, long int index)
{
	short int l;

	l = getlen_short(num);
	num = num / _pow_short(10, l - 1 - index);
	return (num % 10);
}

/**
 * getlen - gets the length of the number num
 * @num: the number to get length of
 *
 * Return: length of number 'num'
 */
short int getlen_long(long int num)
{
	short int i;

	i = 1;
	while (num > 9 || num < -9)
	{
		i++;
		num /= 10;
	}
	return (i);
}
