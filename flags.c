#include "holberton.h"
#include <stdio.h>
#include <stddef.h>

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

int setspecifier(const char *string, param *p, spec *specs)
{
	int offset = 0;
	int i;

	for (i = 0; (specs + i)->spec_string != NULL; i++)
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

int isdig(char c)
{
	int i;
	char digs[11] = "0123456789";

	for (i = 0; digs[i]; i++)
	{
		if (c == digs[i])
			return (1);
	}

	return (0);
}

int get_full(const char *string, spec *specs, param *res)
{
	int offset = 0;
	int specifier;

	/*
	 * printf("Getting params for: %s\n", string);
	 */

	offset = setflags(string, res);
	/*
	 * printf("Got flags: %d, %d, %d, %d\n", res->plus, res->minus,
	 * res->zero, res->space);
	 */
	offset += setwidth(string + offset, res);
	/*
	 * printf("Got width: %d\n", res->width);
	 */
	offset += setprecision(string + offset, res);
	/*
	 * printf("Got precision: %d\n", res->precision);
	 */

	specifier = setspecifier(string + offset, res, specs);
	if (specifier == -1)
		return (-1);

	offset += specifier;
	/*
	 * printf("Got specifier: %s\n", res->specifier->spec_string);
	 */

	return (offset);
}
