#include "holberton.h"

int print_decimal(void *ip)
{
	int i = *(int *)ip;

	print_number(i);

	return (getlen(i));
}

/**
 * print_number - prints a number
 * @n: number to print
 */
void print_number(int n)
{
	int i;

	if (n < 0)
	{
		_putchar('-');
		for (i = 0; i < getlen(n); i++)
			_putchar('0' + -getnum(n, i));
	}
	else
	{
		for (i = 0; i < getlen(n); i++)
			_putchar('0' + getnum(n, i));
	}
}

/**
 * _pow - Calculates exponents
 * @a: base
 * @b: exponent
 *
 * Return: a^b
 */
int _pow(int a, int b)
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
int getnum(int num, int index)
{
	int l;

	l = getlen(num);
	num = num / _pow(10, l - 1 - index);
	return (num % 10);
}

/**
 * getlen - gets the length of the number num
 * @num: the number to get length of
 *
 * Return: length of number 'num'
 */
int getlen(int num)
{
	int i;

	i = 1;
	while (num > 9 || num < -9)
	{
		i++;
		num /= 10;
	}
	return (i);
}
