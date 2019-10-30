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
	param params, zeros = {0, 0, 0, 0, 0, 0, 0, NULL};
	int count = 0, arg_description_len;
	void *vp;

	valist = malloc(sizeof(va_list));
	specs = get_specs();
	if (string == NULL || valist == NULL || specs == NULL || (*string == '%'
				&& string[1] == '\0'))
		return (-1);
	va_start(*valist, string);
	for (i = 0; string[i]; i++)
	{
		if (string[i] == '%')
		{
			if (string[i + 1] == '%')
			{
				count += _putchar('%');
				i++;
				continue;
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
			free(vp);
		}
		count += (string[i] ? _putchar(string[i]) : 0);
	}
	free(specs), free(valist);
	return (count);
}

