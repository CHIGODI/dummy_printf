#include "main.h"
/**
 * print_hexadecimal -handle %x
 * @args: arguments passed
 *
 * Return: NUmber of characters printed
 *
 */
int print_hexadecimal(va_list args)
{
	unsigned long int num = va_arg(args, unsigned long int);
	char hex_digits[] = "0123456789abcdef", *hex_str;
	int char_count, digit_count, i;
	unsigned long int temp;

	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	temp = num;
	digit_count = 0;
	while (temp > 0)
	{
		temp /= 16;
		digit_count++;
	}
	hex_str = malloc(digit_count + 1);
	if (hex_str == NULL)
	{
		return (-1);
	}
	for (i = 0; i < digit_count; i++)
	{
		hex_str[i] = hex_digits[num % 16];
		num /= 16;
	}
	hex_str[digit_count] = '\0';
	reverse(hex_str);
	char_count = strlen(hex_str);
	write(1, hex_str, char_count);
	free(hex_str);
	return (char_count);
}
