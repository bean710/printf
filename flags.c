#include "holberton.h"
#include <stdio.h>
#include <stddef.h>

/**
 * setflags - Sets the flags portion of the pointed to param
 * @string: Pointer to the first character to check for flags
 * @p: Pointer to the param to modify
 *
 * Return: Number of flag chars found (to skip)
 */
int setflags(const char *string, param *p)
{
	unsigned int i, offset = 0;

	do {
		i = 0;
		switch (string[offset])
		{
			case '-':
				p->minus = 1;
				i++;
				break;

			case '+':
				p->plus = 1;
				i++;
				break;

			case '0':
				p->zero = 1;
				i++;
				break;

			case ' ':
				p->space = 1;
				i++;
				break;

			case '#':
				p->pound = 1;
				i++;
				break;

		}
	} while (i && string[++offset]);

	return (offset);
}

/**
 * setwidth - Sets the width portion of the pointed to param
 * @string: Pointer to the first character to check for width
 * @p: Pointer to the param to modify
 *
 * Return: Number of width chars found (to skip)
 */
int setwidth(const char *string, param *p)
{
	int i;

	if (string[0] == '*')
	{
		p->width = -1;
		return (1);
	}

	for (i = 0; string[i] && isdig(string[i]); i++)
	{
		p->width *= 10;
		p->width += (string[i] - '0');
	}

	return (i);
}

/**
 * setprecision - Sets the precision portion of the pointed to param
 * @string: Pointer to the first character to check for precision
 * @p: Pointer to the param to modify
 *
 * Return: Number of precision chars found (to skip)
 */
int setprecision(const char *string, param *p)
{
	int offset = 0;

	if (string[0] == '.' && string[1] == '*')
	{
		p->precision = -1;
		return (2);
	}

	if (string[0] == '.')
	{
		offset++;
		for (; string[offset] && isdig(string[offset]); offset++)
		{
			p->precision *= 10;
			p->precision += (string[offset] - '0');
		}
	}

	return (offset);
}

/**
 * setspecifier - Sets the specifier portion of the pointed to param
 * @string: Pointer to the first character to check for specifier
 * @p: Pointer to the param to modify
 *
 * Return: Number of specifier chars found (to skip)
 */
int setspecifier(const char *string, param *p, spec *specs)
{
	int offset = 0;
	int i;

	for (i = 0; (specs + i)->type != '\0'; i++)
	{
		for (offset = 0; string[offset] &&
				string[offset] == (specs + i)->spec_string[offset]; offset++)
		{
			if ((specs + i)->spec_string[offset + 1] == '\0')
			{
				p->specifier = (specs + i);
				return (offset + 1);
			}
		}
	}

	return (-1);
}

/**
 * isdig - Checks if character is a digit
 * @c: The character to check
 *
 * Return: 1 if digit, 0 if not
 */
int isdig(char c)
{
	return ((c >= '0' && c <= '9') ? 1 : 0);
}
