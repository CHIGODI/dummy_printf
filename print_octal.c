#include "main.h"
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
 * itoo - Converts an integer to an octal string.
 * @num: The integer to be converted.
 * @str: A buffer to store the octal string.
 *
 * Return: 0 on success, -1 on failure.
 */
int itoo(int num, char *str)
{
	if (num == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return 0;
	}

	int is_negative = 0;
	if (num == INT_MIN)
	{
		is_negative = 1;
		num++;
	}
	else if (num < 0)
	{
		is_negative = 1;
		num = -num;
	}
	int index = 0;
	while (num > 0)
	{
		int digit = num % 8;
		str[index++] = digit + '0';
		num /= 8;
	}
	if (is_negative)
	{
		str[index++] = '-';
	}
	str[index] = '\0';
	reverse(str, strlen(str));

    return 0;
}


/**
 * print_octal -handling %o
 * @args: argument passed
 *
 *Return: Number of characters printed
 *
 */
int print_octal(va_list args)
{
	int num = va_arg(args, int);
	int temp = num;
	char *str;
	int count = 0;
	int char_count = 0;

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

	itoo(num, str);
	char_count = write(1, str, strlen(str));
	free(str);
	return (char_count);
}
