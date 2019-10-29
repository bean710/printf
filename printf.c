#include <stdlib.h>
#include <stdio.h>
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
	unsigned int i;
	va_list *valist;
	spec *specs;
	param params;
	param zeros = {0, 0, 0, 0, 0, 0, 0, NULL};
	int count = 0, flag = 0, arg_description_len;
	unsigned int specnum = 0;
	void *vp;

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
			params = zeros;
			arg_description_len = get_full(string + i + 1, specs, &params);
			if (arg_description_len < 0)
			{
				count += _putchar('%');
				continue;
			}
			vp = get_mem(*(params.specifier), valist);
			count += params.specifier->func(vp, params);

			i += arg_description_len + 1;
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
		{"x", print_hex, 'u'},
		{"X", print_hex_u, 'u'},
		{"o", print_oct, 'u'},
		{"u", print_unsig, 'u'},
		{"b", print_binary, 'u'},
		{"r", print_reverse, 's'},
		{"S", print_special, 's'},
		{"R", print_rot, 's'},
		{"li", print_long_decimal, 'l'},
		{"ld", print_long_decimal, 'l'},
		{"ul", print_unsigned_long_decimal, 'L'},
		{"lx", print_long_hex, 'L'},
		{"lX", print_long_hex_u, 'L'},
		{"lo", print_oct_long, 'L'},
		{"hu", print_unsigned_short_decimal, 'H'},
		{"hd", print_short_decimal, 'h'},
		{"hi", print_short_decimal, 'h'},
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
 *
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

		case 'I':
			vp = malloc(sizeof(unsigned int));
			if (vp == NULL)
				return (NULL);
			*(unsigned int *)vp = va_arg(*valist, unsigned int);
			return (vp);

		case 'l':
			vp = malloc(sizeof(long int));
			if (vp == NULL)
				return (NULL);
			*(long int *)vp = va_arg(*valist, long int);
			return (vp);

		case 'L':
			vp = malloc(sizeof(unsigned long int));
			if (vp == NULL)
				return (NULL);
			*(unsigned long int *)vp = va_arg(*valist, unsigned long int);
			return (vp);

		case 'h':
			vp = malloc(sizeof(short int));
			if (vp == NULL)
				return (NULL);
			*(short int *)vp = va_arg(*valist, short int);
			return (vp);

		case 'H':
			vp = malloc(sizeof(unsigned short int));
			if (vp == NULL)
				return (NULL);
			*(unsigned short int *)vp = va_arg(*valist, unsigned short int);
			return (vp);
	}

	return (NULL);
}
