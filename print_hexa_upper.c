#include "main.h"
/**
 * print_hexa_upper - Handle %X
 * @args: argument passed
 *
 * Return: Number of characters printed
 */
int print_hexa_upper(va_list args)
{
	unsigned long int num = va_arg(args, unsigned long int);
	char hex_digits[] = "0123456789ABCDEF", *HEX_str;
	int char_count = 0, i,  digit_count;
	unsigned long  int temp;

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
	HEX_str = malloc(digit_count + 1);

	if (HEX_str == NULL)
	{
		return (-1);
	}
	for (i = 0; i < digit_count; i++)
	{
		HEX_str[i] = hex_digits[num % 16];
		num /= 16;
	}
	HEX_str[digit_count] = '\0';
	reverse(HEX_str);
	char_count = strlen(HEX_str);
	write(1, HEX_str, char_count);
	free(HEX_str);
	return (char_count);
}
