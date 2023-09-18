#include "main.h"
/**
* get_width - hanlding width
* @format - argument
* @i: index
* @args: argument list
*
* Return: width
*/
int get_width(const char *format, int *i, va_list args)
{
	int curr_index, width = 0;

	for (curr_index = *i + 1; format[curr_index] != '\0'; curr_index++)
	{
		if (is_digit(format[curr_index]))
		{
			width *= 10;
			width += format[curr_index] - '0';
		}
		else if (format[curr_index] == '*')
		{
			curr_index++;
			va_arg(args, int);
			break;
		}
		else
		{
			break;
		}
	}
	*i = curr_index - 1;

	return (width);
}
