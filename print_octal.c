#include "main.h"
/**
 * reverse - Reverses a string in-place.
 * @str: The string to be reversed.
 * @length: The length of the string.
 *
 * This function reverses the characters in the given string 'str' in-place.
 * It swaps characters from the beginning
 * and end of the string until the entire
 * string is reversed. The input string 'str' is modified directly.
 *
 * @str: A pointer to the string to be reversed.
 * @length: The length of the string to be reversed.
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
 * itoo - Converts an integer to a string representation with the specified base
 * @num: The integer to be converted.
 * @str: A buffer to store the resulting string.
 * @base: The numeric base for the conversion
 *
 * Return: Void
 */
int itoo(unsigned int num, char *str)
{
	if (num == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (0);
	}
	int index = 0;

	while (num > 0)
	{
		int digit = num % 8;
		str[index++] = digit + '0';
		num /= 8;
	}
	str[index] = '\0';
	reverse(str, strlen(str));
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
	char str[64]; /* Adjust the buffer size as needed */

	itoo(num, str);

	int char_count = write(1, str, strlen(str));
	
	return (char_count);
}
