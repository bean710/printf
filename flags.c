#include "holberton.h"
#include <stddef.h>

int setflags(const char *string, param *p)
{
	unsigned int i, offset = 0;
	unsigned char result = 0;

	do
	{
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
		}
	} while (i && string[++offset]);

	return (offset);
}

int setwidth(const char *string, param *p)
{
	int i;

	if (string[0] == '*')
		return (-1);

	for (i = 0; string[i] && isdig(string[i]); i++)
	{
		p->width *= 10;
		p->width += (string[i] - '0');
	}

	return (i);
}

int setprecision(const char *string, param* p)
{
	int offset = 0;

	if (string[0] == '.')
	{
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

	for (i = 0; (specs + i)->func != NULL; i++)
	{
		for (offset = 0; string[offset] == (specs + i)->spec_string[offset];
				offset++)
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

param get_full(const char *string, spec *specs)
{
	int i;
	char flags;
	int offset = 0;

	param res = {0, 0, 0, 0, 0, 0};

	offset = setflags(string, &res);
	offset += setwidth(string + offset, &res);
	offset += setprecision(string + offset, &res);

	offset += setspecifier(string + offset, &res, specs);

	return (res);
}
