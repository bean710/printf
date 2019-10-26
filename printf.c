#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "holberton.h"

int _printf(const char *string, ...)
{
	int i, k;
	void *vp;
	va_list *valist;
	int count = 0, flag = 0;

	valist = malloc(sizeof(va_list));
	if (valist == NULL)
		return (-1);

	va_start(*valist, string);

	spec specs[] = {
		{"i", print_decimal, 'i'},
		{"d", print_decimal, 'i'},
		{"s", print_string, 's'},
		{"c", print_char, 'i'}
	};

	for (i = 0; string[i]; i++)
	{
		flag = 0;
		if (string[i] == '%')
		{
			if (string[i + 1] == '%')
			{
				_putchar('%');
				i++;
				count++;
				flag = 1;
			}

			for (k = 0; k < 4 && flag == 0; k++)
			{
				if (*(specs[k].spec_string) == string[i + 1])
				{
					vp = get_mem(specs[k], valist);
					count += specs[k].func(vp);
					i++;
					flag = 1;
				}
			}
		}

		if (flag == 0)
		{
			_putchar(string[i]);
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
