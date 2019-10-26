#ifndef _FOO_
#define _FOO_

#include <stdarg.h>

/**
 * struct specifier - for comparing printf specifiers.
 * @spec_string: The printf specifier
 * @func: The specifier's corresponding function pointer
 * @type: The type of input the function takes, represented as a char.
 *
 * Description: This will be used as an array. It will hold all the printf
 * specifiers in spec_string, it's corresponding function pointer in func, and
 * the type of input the function takes in type.
 */
typedef struct specifier
{
	char *spec_string;
	int (*func)(void *);
	char type;
} spec;

void print_number(int n);
int _pow(int a, int b);
int getnum(int num, int index);
int getlen(int num);
int print_decimal(void *);
int print_string(void *);
void *get_mem(spec, va_list *);

#endif
