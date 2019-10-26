#ifndef _FOO_
#define _FOO_

#include <stdarg.h>

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
int print_string(void *);
void *get_mem(spec, va_list *);

#endif
