#include "main.h"
/**
 *
 */
int print_string(va_list args)
{
	int len;
	char *str;

	str = va_arg(args, char *);
	len =strlen(str);
	return (write(1, str, len));
}
