#include <stdlib.h>
#include <stdarg.h>
#include "holberton.h"

/**
 * _printf - prints data to standard out
 * @string: Char string that will include specifiers
 * Return: the number of characters printed.
 */
int _printf(const char *string, ...)
{
	int i, k;
	void *vp;
	va_list *valist;
	spec *specs;
	int count = 0, flag = 0;

	valist = malloc(sizeof(va_list));
	specs = get_specs();
	if (valist == NULL || specs == NULL)
		return (-1);
	va_start(*valist, string);
	for (i = 0; string[i]; i++)
	{
		flag = 0;
		if (string[i] == '%')
		{
			if (string[i + 1] == '%')
			{
				count += _putchar('%');
				i++;
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
			count += _putchar(string[i]);
	}
	return (count);
}

/**
 * get_specs - Gives a pointer to allocated space containing all predefined
 * spec structs
 * 
 * Return: Pointer to the first element in an array of `spec`s
 */
spec *get_specs(void)
{
	const int num = 4;
	int i;
	spec *ret_spec = malloc(sizeof(spec) * num);

	if (ret_spec == NULL)
		return (NULL);

	spec specs[] = {
		{"i", print_decimal, 'i'},
		{"d", print_decimal, 'i'},
		{"s", print_string, 's'},
		{"c", print_char, 'i'}
	};

	for (i = 0; i < num; i++)
		ret_spec[i] = specs[i];

	return (ret_spec);
}

/**
 * get_mem - returns a malloc'd void pointer
 * @s: struct
 * @valist: pointer of type va_list
 * Return: void pointer
 */
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
