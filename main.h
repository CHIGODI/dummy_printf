#ifndef MAIN_H
#define MAIN_H
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>




#define BUFFER_SIZE 1024




int _printf(const char *format, ...);
int (*format_handler(const char *format, int *int_ptr))(va_list);
int print_string(va_list args);
int print_percent(va_list args);
int print_char(va_list args);
int print_int(va_list args);
int print_binary(va_list args);
int print_unsigned(va_list args);
int print_octal(va_list args);
int print_hexadecimal(va_list args);
int print_hexa_upper(va_list args);
int print_pointer(va_list args);
int print_non_printable(va_list args);
int print_reverse(va_list args);

#endif
