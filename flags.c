#include "holberton.h";

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
	} while (i && string[++ofset])

	return (offset);
}

int setwidth(const char *string, param *p)
{
	int i;

	if (string[0] == '*')
		return (-1);

	for (i = 0; isdig(string[i]; i++))
	{
		p->width *= 10;
		p->width += (string[i] - '0');
	}

	return (i);
}

int setprecision(const char *string)
{
	int precision = 0;
	int i;


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

param get_full(const char *string, unsigned int specnum)
{
	int i;
	char flags;
	int offset = 0;

	param res = {0, 0, 0, 0, 0, 0};

	offset = setflags(string, &res);
	offset += setwidth(string + offset, &res);
	offset += setprecision(string + offset, &res);

	return (res);
}
