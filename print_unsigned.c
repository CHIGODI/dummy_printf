#include "main.h"
/**
 * reverse - Reverses a string
 * @str: The string to be reversed
 * @length: The length of the string
 *
 * Description: This function reverses the characters in the given string.
 */
static void reverse(char *str, int length)
{
	int start = 0;
	int end = length - 1;

	while (start < end)
	{
		char temp = str[start];

		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}
/**
 * itoa_unsigned - Converts an unsigned integer to a
 * string representation with the specified base
 * @num: The unsigned integer to be converted.
 * @str: A buffer to store the resulting string.
 * @base: The numeric base for the conversion
 *
 * Return: Void
 */
void itoa_unsigned(unsigned int num, char *str, int base)
{
	int i = 0;

	if (num == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return;
	}

	while (num != 0)
	{
		int rem = num % base;

		str[i++] = rem + '0';
		num /= base;
	}
	str[i] = '\0';
	reverse(str, i);
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
	int char_count = 0;

	if (num == 0)
	{
		char_count += write(1, "0", 1);
	}
	else
	{
		int digit_count = 0;
		unsigned int temp = num;

		while (temp != 0)
		{
			temp /= 10;
			digit_count++;
		}
		while (digit_count > 0)
		{
			unsigned int divisor = 1;
			int i;

			for (i = 1; i < digit_count; i++)
			{
				divisor *= 10;
			}

			char digit = '0' + (num / divisor);

			char_count += write(1, &digit, 1);
			num %= divisor;
			digit_count--;
		}
	}
	return (char_count);
}
