#include "holberton.h"

int print_unsigned_long_decimal(void *ulivp, param params)
{
	int uli = *(unsigned long int *)ulivp;
	int count = 0;

	return (long_base_converter(uli, 10, "0123456789") + count);
}
