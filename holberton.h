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

void *get_mem(spec, va_list *);
int _putchar(char);
int _printf(const char *, ...);
int print_binary(void *);
unsigned int u_pow(unsigned int, unsigned int);
int print_reverse(void *);

/* long number functions */
int long_base_converter(unsigned long int i, unsigned long int base, char *set);
int print_long_hex(void *luhp);
int print_long_hex_u(void *luhp);
int print_unsig_long(void *luip);
int print_ptr(void *p);
int print_oct_long(void *luop);

/* short number functions */
int short_base_conv(unsigned short int i, unsigned short int base, char *set);
int print_short_hex(void *suhp);
int print_short_hex_u(void *suhp);
int print_oct_short(void *suop);
int print_unsig_short(void *suip);

#endif
