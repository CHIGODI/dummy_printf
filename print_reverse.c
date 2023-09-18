#include "main.h"
/**
 * print_reverse - handle printing string in reverse
 * @args: argument list
 *
 * Return: reversed number of characters printed
 */
int print_reverse(va_list args)
{
	char *str, rstr;
	int i, count = 0;

	str = va_arg(args, char *);

	if (str == NULL)
	{
		return (-1);
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		rstr = str[i];

		write(1, &rstr, 1);
		count++;
	}
	return (count);
}
