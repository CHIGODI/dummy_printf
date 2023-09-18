#include "main.h"
/**
 * _printf - imulate printf
 * @format: format specifier
 *
 * Return: NUmber of characters printed
 */

int _printf(const char *format, ...)
{
	int i = 0, printed_chars = 0;
	int (*printer)(va_list);
	int precision;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			precision = get_precision(format, &i, list);
			printer = format_handler(format, &i);

			if (printer)
			{
				printed_chars += printer(args);
			}
			else
			{
				return (-1);
			}
		}
		else
		{
			printed_chars += write(1, &format[i], 1);
		}
	}

	va_end(args);
	return (printed_chars);
}
