#include "holberton.h"

int print_oct(void *uop)
{
	unsigned int oct = *(unsigned int *)uop;

	return (base_converter(oct, 8, "01234567"));
}
