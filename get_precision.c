#include "main.h"
/**
 * get_precision - handling precision
 * @format: arguments passed to printf
 * @i: pointer to current index
 * @args: argumets list
 *
 * Return: precision
 */
int get_precision(const char *format, int *i, va_list args)
{
	int curr_index = *i + 1;
	int precision = -1;

	if (format[curr_index] != '.')
		return (precision);

	precision = 0;

	for (curr_index + 1; format[curr_index] != '\0'; curr_index++)
	{
		if (is_digit(format[curr_index]))
		{
			precision *= 10;
			precision += format[curr_index] - '0';
		}
		else if (format[curr_index] == '*')
		{
			curr_index++;
			precision = va_arg(args, int);
			break;
		}
		else
		{
			break;
		}

	}
	*i = curr_index - 1;

	return (precision);
}
