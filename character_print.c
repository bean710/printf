#include "holberton.h"

/**
 * print_char - Prints a character from a void pointer
 * @cp: Void pointer which points to an address where a character is stored
 * @params: a structure containing info about the argument
 * Return: Number of characters printed (Always 1)
 */
int print_char(void *cp, param params)
{
	int c = *(int *)cp;

	_putchar(c);
	return (1);
}
