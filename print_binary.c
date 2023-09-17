#include "main.h"
/**
 * reverse - Reverses a string in-place.
 * @str: The string to be reversed.
 * @length: The length of the string.
 *
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
 * itob - Converts an unsigned integer to a binary string.
 * @num: The unsigned integer to be converted.
 * @str: A buffer to store the binary string.
 *
 * Return: Void
 *
 */
void itob(unsigned int num, char *str)
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
		int bit = num % 2;
		str[i++] = bit + '0';
		num /= 2;
	}
	str[i] = '\0';
	reverse(str, i);
}



/**
 * print_binary - function to handle custome %b
 * @args: argments passed
 *
 * Return: Number of characters printed
 */

int print_binary(va_list args)
{
	int count = 0;
	unsigned int num = va_arg(args, unsigned int);
	unsigned int temp = num;
	char *str;

        /*calculate number of binary digits needed*/
	while (temp != 0)
	{
		temp /= 2;
		count++;
	}

	str = malloc((sizeof(char) * count) + 1);
	itob(num, str);
	if (str != NULL)
	{
		write(1, str, strlen(str));
		free(str);
		return (count);
	}
	return (-1);
}
