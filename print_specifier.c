#include "main.h"

/**
 * print_c - print char
 * @ap: argument list
 * @flag: flag for some functions not used here
 * Return: number of character printed
 */
int print_c(va_list ap, int flag)
{
	char c;

	if (flag < 0)
		return (-1);
	c = va_arg(ap, int);

	return (_putchar(c));
}

/**
 * print_s - print string
 * @ap: argument list
 * @flag: flag for some functions not used here
 * Return: number of characters printed
 */
int print_s(va_list ap, int flag)
{
	int i = 0, count = 0;
	char *s = va_arg(ap, char *);

	if (flag < 0)
		return (-1);

	while (s[i])
	{
		if ((s[i] < 32 || s[i] > 126) && flag == 9)
		{
			_printf("\\x%02X", (unsigned int) s[i]);
		}
		else
			count += _putchar(s[i]);
		i++;
	}

	return (count);
}

/**
 * print_int - call print_num function to print integer
 * @ap: argument list
 * @flag: tells if it is %i or %d or %b specifier
 * Return: number of characters printed
 */
int print_int(va_list ap, int flag)
{
	int num = va_arg(ap, int), base = 10;

	if (flag == 4)
		base = 2;

	return (print_num(num, base));
}

/**
 * print_unsigned_int - call print_num function to print integer
 * @ap: argument list
 * @flag: tells if it is %i or %d or %b specifier
 * Return: number of characters printed
 */
int print_unsigned_int(va_list ap, int flag)
{
	unsigned int num = va_arg(ap, unsigned int);
	int base = 10;
	bool small = true;

	if (flag == 6)
		base = 8;
	if (flag == 7 || flag == 8)
	{
		if (flag == 8)
			small = false;
		base = 16;
	}
	return (print_positive_num(num, base, small));
}

/**
 * print_num - print numbers
 * @n: number to be printed
 * @base: base of the number to be printed
 * Return: number of characters printed
 */
int print_num(int n, int base)
{
	int num_chars = 0;

	if (base == 2)
	{
		if (n > 1)
			num_chars += print_num(n / base, base);
		num_chars += _putchar('0' + n % base);
	}
	else
	{
		if (n < 0)
		{
			_putchar('-');
			n = -n;
			num_chars++;
		}
		if (n > 9)
			num_chars += print_num(n / base, base);
		num_chars += _putchar('0' + n % base);
	}
	return (num_chars);
}
