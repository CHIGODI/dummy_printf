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
 * itoa - Converts an integer to a string representation with the specified base.
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
 * print_int - printing integers
 * @args: intger argument
 *
 * Return: number of characters printed
 */

int print_int(va_list args)
{
	int num = va_arg(args, int);
	int count = 0;
	int temp = num;
	char *str;

	while (temp != 0)
	{
		temp /= 10; /* Use /= to update temp with the quotient*/
		count++;
	}

	/* Allocate memory for the string*/
	str = malloc((sizeof(char) * count) + 1);

	if (str != NULL)
	{
		/* Call your itoa function to convert the integer to a string*/
		itoa(num, str, 10);

		/* Write the string to the standard output*/
		int chars_written = write(1, str, strlen(str));

		/* Free the allocated memory*/
		free(str);

		return (chars_written);
	}

	return -1;
}
