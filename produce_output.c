#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: is a character string.
 *
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	int i = 0, j = 0, count = 0;
	char *specifiers = "csidbuoxXS";
	int (*ptr[])(va_list, int) = {print_c, print_s, print_int,
		print_unsigned_int};
	va_list ap;

	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '%')
		{
			j = 0;
			while (j < 10)
			{
				if (format[i + 1] == specifiers[j])
				{
					if (j >= 2 && j <= 4)
						count += ptr[2](ap, j);
					else if (j >= 5 && j <= 8)
						count += ptr[3](ap, j);
					else if (j == 1 || j == 9)
						count += ptr[1](ap, j);
					else
						count += ptr[j](ap, j);
					i++;
					break;
				}
				j++;
			}
		}
		else
			count += _putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (count);
}
