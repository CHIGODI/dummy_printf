#include "main.h"
/**
 * print_string - handles %s
 * @args: arguments passed
 *
 * Return: number of character printed
 */
int print_string(va_list args)
{
	int len;
	char *str;

	str = va_arg(args, char *);
	len = strlen(str);
	return (write(1, str, len));
}
