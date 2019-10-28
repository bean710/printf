#include <stdlib.h>
#include <stdarg.h>
#include "holberton.h"

/**
 * _printf - prints data to standard out
 * @string: Char string that will include specifiers
 *
 * Return: the number of characters printed.
 */
int _printf(const char *string, ...)
{
	unsigned int i, k;
	void *vp;
	va_list *valist;
	spec *specs;
	int count = 0, flag = 0;
	unsigned int specnum = 0;

	valist = malloc(sizeof(va_list));
	specs = get_specs(&specnum);
	if (string == NULL || valist == NULL || specs == NULL || (*string == '%'
				&& string[1] == '\0'))
		return (-1);
	va_start(*valist, string);
	for (i = 0; string[i]; i++, flag = 0)
	{
		if (string[i] == '%')
		{
			if (string[i + 1] == '%')
			{
				count += _putchar('%');
				i++;
				flag = 1;
			}
			for (k = 0; k < specnum && flag == 0; k++)
			{
				if (*(specs[k].spec_string) == string[i + 1])
				{
					vp = get_mem(specs[k], valist);
					count += specs[k].func(vp);
					free(vp);
					i++;
					flag = 1;
				}
			}
		}
		if (flag == 0)
			count += _putchar(string[i]);
	}
	free(specs), free(valist);
	return (count);
}

/**
 * get_specs - Gives a pointer to allocated space containing all predefined
 * spec structs
 * @i: Pointer to an unsigned int which will be iterated based on how many
 * spec strucs will be returnes
 *
 * Return: Pointer to the first element in an array of `spec`s
 */
spec *get_specs(unsigned int *i)
{
	spec *ret_spec;
	unsigned int j;
	spec specs[] = {
		{"i", print_decimal, 'i'},
		{"d", print_decimal, 'i'},
		{"s", print_string, 's'},
		{"c", print_char, 'i'},
		{NULL, NULL, '\0'}
	};

	for (; specs[*i].spec_string != NULL; (*i)++)
		;

	ret_spec = malloc(sizeof(spec) * (*i));
	if (ret_spec == NULL)
		return (NULL);

	for (j = 0; j < *i; j++)
		ret_spec[j] = specs[j];

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
