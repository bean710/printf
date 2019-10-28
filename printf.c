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
	unsigned int i;
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
			i += loop_specifiers(valist, specnum, string[i + 1], specs,
					&count, &flag);
		}
		if (flag == 0)
			count += _putchar(string[i]);
	}
	free(specs), free(valist);
	return (count);
}

/**
 * loop_specifiers - Loops through the specifiers and runs a function if it
 * exists
 * @valist: Address of the va_list variable to use
 * @specnum: Number of specifiers to loop through
 * @specifier: The character from the format string that could be a specifier
 * @specs: Pointer to the first spec in an array of valid specifiers
 * @count: Pointer to the int that counts the number of characters printed
 * @flag: A flag to signal if a specifier was found
 *
 * Return: How many characters should be skipped based on if a specifier was
 * found or not
 */
int loop_specifiers(va_list *valist, unsigned int specnum, char specifier,
		spec *specs, int *count, int *flag)
{
	unsigned int k;
	void *vp;

	for (k = 0; k < specnum && *flag == 0; k++)
	{
		if (*(specs[k].spec_string) == specifier)
		{
			vp = get_mem(specs[k], valist);
			(*count) += specs[k].func(vp);
			free(vp);
			*flag = 1;
			return (1);
		}
	}

	return (0);
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

		case 'u':
			vp = malloc(sizeof(unsigned int));
			if (vp == NULL)
				return (NULL);
			*(unsigned int *)vp = va_arg(*valist, unsigned int);
			return (vp);
	}

	return (NULL);
}
