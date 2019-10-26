#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "holberton.h"

int _printf(char *string, ...)
{
	int i, j, k;
	void *vp;
	va_list *valist;
	int count = 0;

	valist = malloc(sizeof(va_list));
	if (valist == NULL)
		return (-1);

	va_start(*valist, string);

	spec specs[] = {
		{"s", print_string, 's'}
	};

	for (i = 0; string[i]; i++)
	{
		if (string[i] == '%')
		{
			j = i + 1;
			for (k = 0; k < 2; k++)
			{
				if (*(specs[k].spec_string) == string[j])
				{
					vp = get_mem(specs[k], valist);
					count += specs[k].func(vp);
					i += 2;
				}
			}
		}

		if (string[i])
		{
			putchar(string[i]);
			count++;
		}
	}

	return (count);
}

void *get_mem(spec s, va_list *valist)
{
	void *vp;

	switch (s.type)
	{
		case 'i':
			vp = malloc(sizeof(int));
			if (vp == NULL)
				return (NULL);
			*(int *)vp = va_arg(*valist, int);
			return (vp);

		case 's':
			vp = malloc(sizeof(char *));
			if (vp == NULL)
				return (NULL);
			*(char **)vp = va_arg(*valist, char *);
			return (vp);
	}

	return (NULL);
}
