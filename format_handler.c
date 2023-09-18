#include "main.h"

/**
 * format_handler - handling any format to call the appropriate func
 * @format: format to handle
 * @int_ptr: this is used to loop through the format
 *
 * Return: Appropriate function to be called in case of a type format.
 */
int (*format_handler(const char *format, int *int_ptr))(va_list)
{
	int i = 0;
	fmt fmt_type[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		 {'d', print_int}, {'i', print_int}, {'b', print_binary},
		 {'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		 {'X', print_hexa_upper},
		 {'\0', NULL}
	};

	while (fmt_type[i].ch != '\0')
	{
		if (fmt_type[i].ch == format[*int_ptr])
		{
			return (fmt_type[i].func);
		}
		i++;
	}

	return (NULL);
}
