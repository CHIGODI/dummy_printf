#include "main.h"
/**
 * print_char - handles character
 * @va_list: arguments
 *
 * Return: nuber of characters
 */
int print_char(va_list args)
{
	char ch = va_arg(args, int);

	return (write(1, &ch, 1));
}
