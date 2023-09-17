#include "main.h"
/**
 * _printf - imulate printf
 * @format: format specifier
 *
 * Return: NUmber of characters printed
 */

int _printf(const char *format, ...)
{
	va_list args;
	int i = 0;
	int printed_chars = 0;

	va_start(args, format);

	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			int (*printer)(va_list) = format_handler(format, &i);
			if (printer)
			{
				printed_chars += printer(args);
			}
			else
			{
				printed_chars += write(1, "ERROR", 5);
			}
		}
		else
		{
			printed_chars += write(1, &format[i], 1);
		}
		i++;
	}

	va_end(args);
	return printed_chars;
}
