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

typedef struct parameters
{
	int flag[4];
	int width;
	int precision;
} param;

spec *get_specs(unsigned int *);
void print_number(int n);
int _pow(int a, int b);
int getnum(int num, int index);
int getlen(int num);
int base_converter(unsigned int, unsigned int, char *);

int print_decimal(void *);
int print_string(void *);
int print_char(void *);
int print_hex(void *);
int print_hex_u(void *);
int print_oct(void *);
int print_unsig(void *);
int print_special(void *);

void *get_mem(spec, va_list *);
int loop_specifiers(va_list *, unsigned int, char, spec *, int *, int *);
int _putchar(char);
int _printf(const char *, ...);
int print_binary(void *);
unsigned int u_pow(unsigned int, unsigned int);
int print_reverse(void *);
int print_rot(void *);

#endif
