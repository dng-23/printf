#include "main.h"

/**
 * print_positive_num - print positive numbers according to their base
 * @n: number to be printed
 * @base: number's base
 * @small: flag to differentiate between %x and %X
 * Return: number of characters printed
 */
int print_positive_num(unsigned int n, int base, bool small)
{
	int num_chars = 0, digit;

	num_chars += print_num(n / base, base);
	digit = n % base;
	if (digit > 10)
	{
		if (small)
			num_chars += _putchar('a' + (digit - 10));
		else
			num_chars += _putchar('A' + (digit - 10));
	}
	else
		num_chars += _putchar('0' + digit);
	return (num_chars);
}
