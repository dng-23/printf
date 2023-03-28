#include "main.h"

/**
 * print_positive_num - print positive numbers according to their base
 * @n: number to be printed
 * @base: number's base
 * @small: flag to differentiate between %x and %X
 * @prec: precision
 * Return: number of characters printed
 */
int print_positive_num(unsigned int n, int base, bool small, int prec)
{
	int num_chars = 0, digit, len = num_len((int) n, base);

	while (prec > len)
	{
		_putchar('0');
		prec--;
	}
	num_chars += print_num(n / base, base, 0);
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

/**
 * num_len - calculate length of number
 * @num: number to be calculated
 * @base: number's base
 * Return: number of characters printed
 */
int num_len(int num, int base)
{
	int len = 0;

	do {
		num /= base;
		len++;
	} while (num > 0);
	return (len);
}
