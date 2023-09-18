#include "main.h"
/**
 * itoo - Converts an integer to a string representation with the specified base
 * @num: The integer to be converted.
 * @str: A buffer to store the resulting string.
 * @base: The numeric base for the conversion
 *
 * Return: Void
 */
int itoo(unsigned int num, char *str)
{
	int index, digit;

	if (num == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (0);
	}
	index = 0;

	while (num > 0)
	{
		digit = num % 8;
		str[index++] = digit + '0';
		num /= 8;
	}
	str[index] = '\0';
	reverse(str);
	return (0);
}
/**
 * print_octal - Handles the %o format specifier
 * @args: Argument list containing the value to print
 *
 * Return: The number of characters printed
 *
 * Description: This function prints an unsigned integer as an octal number.
 */
int print_octal(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char *str;
	unsigned int temp = num;
	int char_count, count = 0;

	while (temp != 0)
	{
		temp /= 8;
		count++;
	}
	str = malloc((sizeof(char) * count) + 1);
	if (str == NULL)
	{
		return (-1);
	}
	else
	{
		itoo(num, str);

		char_count = write(1, str, strlen(str));
		free(str);
	}
	return (char_count);
}
