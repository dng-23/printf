#ifndef MAIN
#define MAIN

#include <stdarg.h>
#include <stddef.h>
#include <stdbool.h>
int _putchar(char c);
int _printf(const char *format, ...);

int print_c(va_list, int);
int print_s(va_list, int);
int print_int(va_list, int);
int print_unsigned_int(va_list, int);
int print_positive_num(unsigned int, int, bool);

int print_num(int, int);
#endif
