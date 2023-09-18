#include "main.h"
/**
 * get_flags - handles flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter
 *
 * Return: Flags:
 */
int get_flags(const char *format, int *i)
{
	int curr_index, j, flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {FLAG_MINUS, FLAG_PLUS, FLAG_ZERO, FLAG_HASH,
		FLAG_SPACE, 0};

	for (curr_index = *i + 1; format[curr_index]  != '\0'; curr_index++)
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
		{
			if (format[curr_index] == FLAGS_CHAR[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

			if (FLAGS_CH[j] == 0)
				break;

		}
	i* = curr_index - 1;
	return (flags);
}
