#ifndef _FOO_
#define _FOO_

#include <stdarg.h>

struct specifier;
/**
 * struct parameters - for storing printf argument descriptions
 * @plus: '+' flag
 * @minus: '-' flag
 * @zero: '0' flag
 * @space: ' ' flag
 * @pound: '#' flag
 * @width: int value of width
 * @precision: int value of precision
 * @specifier: a struct with a specifier, it's relevant function ptr, and type
 */
typedef struct parameters
{
	/* Flags */
	char plus;
	char minus;
	char zero;
	char space;
	char pound;

	int width;
	int precision;

	struct specifier *specifier;
} param;

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
	int (*func)(void *, param);
	char type;
} spec;

spec *get_specs(unsigned int *);
void print_number(int n);
int _pow(int a, int b);
int getnum(int num, int index);
int getlen(int num);
int base_converter(unsigned int, unsigned int, char *);

int setflags(const char *string, param *p);
int setwidth(const char *string, param *p);
int setprecision(const char *string, param* p);
int setspecifier(const char *string, param *p, spec *specs);
int isdig(char c);
int get_full(const char *string, spec *specs, param *);

void *get_mem(spec, va_list *);
int loop_specifiers(va_list *, unsigned int, char, spec *, int *, int *);
int _putchar(char);
int _printf(const char *, ...);
int print_binary(void *, param);
unsigned int u_pow(unsigned int, unsigned int);
int print_reverse(void *, param);
int print_rot(void *, param);

int print_decimal(void *, param);
int print_string(void *, param);
int print_char(void *, param);
int print_hex(void *, param);
int print_hex_u(void *, param);
int print_oct(void *, param);
int print_unsig(void *, param);
int print_special(void *, param);

/* long number functions */
int long_base_converter(unsigned long int i, unsigned long int base, char *set);
int print_long_hex(void *luhp, param);
int print_long_hex_u(void *luhp, param);
int print_unsig_long(void *luip, param);
int print_ptr(void *p, param);
int print_oct_long(void *luop, param);

int print_long_decimal(void *ip, param p);
void print_long_number(long int n);
int _pow_long(int a, int b);
int getnum_long(long int num, long int index);
long int getlen_long(long int num);

/* short number functions */
int short_base_conv(unsigned short int i, unsigned short int base, char *set);
int print_short_hex(void *suhp, param);
int print_short_hex_u(void *suhp, param);
int print_oct_short(void *suop, param);
int print_unsig_short(void *suip, param);

#endif
