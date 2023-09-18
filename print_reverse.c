#include "main.h"
/**
 * print_reverse - handle printing string in reverse
 * @args: argument list
 *
 * Return: reversed string
 */
char print_reverse(va_list args)
{
	char *str = va_arg(args, char *);

	int len = strlen(str);

	reverse(str);

	return (write(1, str, len));
}
