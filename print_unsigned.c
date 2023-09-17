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
 * itoa - Converts an integer to a string representation with the specified base
 * @num: The integer to be converted.
 * @str: A buffer to store the resulting string.
 * @base: The numeric base for the conversion
 *
 * Return: Void
 */
void itoa(int num, char *str, int base)
{
        int i = 0, rem;
        bool isNegative = false;

        if (num == 0)
        {
                str[i++] = '0';
                str[i] = '\0';
                return;
        }

        if (num < 0 && base == 10)
        {
                isNegative = true;
                num = -num;
        }

        while (num != 0)
        {
                rem = num % base;
                str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
                num /= base;
        }

        if (isNegative)
        {
                str[i++] = '-';
        }
        str[i] = '\0';

        reverse(str, i);
}

/**
 * print_unsigned - handle %u
 * @args: argument passed
 *
 * Return: Number of characters printed or -1 on failure
 */
int print_unsigned(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	unsigned int temp = num;
	char *str;
	int count = 0;
	int char_count = 0;

	while (temp != 0)
	{
		temp /= 10;
		count++;
	}

        str = malloc((sizeof(char) * count) + 1);
	if (str == NULL)
	{
		return (-1);
	}
        itoa(num, str, 10);
        char_count = write(1, str, strlen(str));

	free(str);
	return char_count;
}
