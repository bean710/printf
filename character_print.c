#include "holberton.h"

int print_char(void *cp)
{
	int c = *(int *)cp;

	putchar(c);
}
