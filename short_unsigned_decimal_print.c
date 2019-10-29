#include "holberton.h"

int print_unsigned_short_decimal(void *usivp, param params)
{
	unsigned short int usi = *(unsigned short int *)usivp;

	return (short_base_conv(usi, 10, "0123456789"));
}
