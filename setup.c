#include <stdlib.h>
#include <stdarg.h>
#include "holberton.h"

/**
 * get_specs - Gives a pointer to allocated space containing all predefined
 * spec structs
 * spec strucs will be returnes
 *
 * Return: Pointer to the first element in an array of `spec`s
 */
spec *get_specs(void)
{
	spec *ret_spec;
	unsigned int j;
	spec specs[] = {
		{"i", print_decimal, 'i'},
		{"d", print_decimal, 'i'},
		{"s", print_string, 's'},
		{"c", print_char, 'i'},
		{"x", print_hex, 'I'},
		{"X", print_hex_u, 'I'},
		{"o", print_oct, 'I'},
		{"u", print_unsig, 'I'},
		{"b", print_binary, 'I'},
		{"r", print_reverse, 's'},
		{"S", print_special, 's'},
		{"R", print_rot, 's'},
		{"p", print_ptr, 'L'},
		{"li", print_long_decimal, 'l'},
		{"ld", print_long_decimal, 'l'},
		{"lu", print_unsigned_long_decimal, 'L'},
		{"lx", print_long_hex, 'L'},
		{"lX", print_long_hex_u, 'L'},
		{"lo", print_oct_long, 'L'},
		{"hu", print_unsigned_short_decimal, 'i'},
		{"hd", print_short_decimal, 'i'},
		{"hi", print_short_decimal, 'i'},
		{"ho", print_oct_short, 'i'},
		{"hx", print_short_hex, 'i'},
		{"hX", print_short_hex_u, 'i'},
		{NULL, NULL, '\0'}
	};

	ret_spec = malloc(sizeof(spec) * 26);
	if (ret_spec == NULL)
		return (NULL);
	for (j = 0; j < 26; j++)
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
			vp = malloc(sizeof(unsigned long));
			if (vp == NULL)
				return (NULL);
			*(unsigned long *)vp = va_arg(*valist, unsigned long);
			return (vp);
	}
	return (NULL);
}

/**
 * get_full - Gets the full set of flags, witdth, precision, and the
 * specifier (Using functions in flags.c
 * @string: Pointer to the first character to check for flags, width, etc.
 * @specs: Pointer to the list of specifiers
 * @res: Pointer to the param struct to change the attributes of
 *
 * Return: Number of characters contained in the specifier including all
 * flags, width, precision and specifiers (Not including the %)
 */
int get_full(const char *string, spec *specs, param *res)
{
	int offset = 0;
	int specifier;


	/* printf("Getting params for: %s\n", string); */


	offset = setflags(string, res);

	/* printf("Got flags: %d, %d, %d, %d\n", res->plus, res->minus, */
	/* res->zero, res->space); */

	offset += setwidth(string + offset, res);

	/* printf("Got width: %d\n", res->width); */

	offset += setprecision(string + offset, res);

	/* printf("Got precision: %d\n", res->precision); */


	specifier = setspecifier(string + offset, res, specs);
	if (specifier == -1)
		return (-1);

	offset += specifier;

	/* printf("Got specifier: %s\n", res->specifier->spec_string); */


	return (offset);
}
