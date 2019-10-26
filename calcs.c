#include "holberton.h"

int print_decimal(void *ip)
{
	int i = *(int *)ip;

	print_number(i);

	return (getlen(i));
}

int print_string(void *sp)
{
	char *s = *(char **)sp;
	int i = 0;

	for (; *s; s++, i++)
		putchar(*s);

	return (i);
}
