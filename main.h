#ifndef MAIN_H
#define MAIN_H
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>




#define BUFFER_SIZE 1024
/**
 * struct case_fmt - Mapping between format specifiers and handling functions.
 * @ch: The character representing a format specifier.
 * @func: A function pointer to the corresponding handling function.
 *
 */
struct case_fmt
{
	char ch;
	int (*func)(va_list);
};

typedef struct case_fmt fmt;



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

/*helper functions */
void reverse(char *s);


#endif
