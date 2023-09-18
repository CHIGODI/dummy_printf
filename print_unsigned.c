#include "main.h"

/**
 * itoa_unsign - Converts an unsigned integer to a
 * string representation with the specified base
 * @num: The unsigned integer to be converted.
 * @str: A buffer to store the resulting string.
 * @base: The numeric base for the conversion
 *
 * Return: Void
 */
void itoa_unsign(unsigned int num, char *str, int base)
{
	int i = 0;
	unsigned int rem;

	if (num == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return;
	}

	while (num != 0)
	{
		rem = num % base;

		str[i++] = rem + '0';
		num /= base;
	}
	str[i] = '\0';
	reverse(str);
}

/**
 * print_unsigned - Handle %u
 * @args: Argument passed
 *
 * Return: Number of characters printed or -1 on failure
 */
int print_unsigned(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int char_count = 0, digit_count;
	unsigned int temp;
	char *str;

	if (num == 0)
	{
		char_count += write(1, "0", 1);
	}

	digit_count = 0;
	temp = num;

	while (temp != 0)
	{
		temp /= 10;
		digit_count++;
	}
	str = malloc((sizeof(char) * digit_count) + 1);

	if (str == NULL)
	{
		return (-1);
	}

	itoa_unsign(num, str, 10);
	char_count = strlen(str);
	write(1, str, char_count);
	free(str);
	return (char_count);
}
