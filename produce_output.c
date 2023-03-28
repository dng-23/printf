#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: is a character string.
 *
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	int i = 0, j = 0, count = 0, p = 0;
	char *specifiers = "csidbuoxXS", *precision = "0123456789";
	int (*ptr[])(va_list, int, int) = {print_c, print_s, print_int,
		print_unsigned_int};
	va_list ap;

	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '%')
		{
			for (j = 0; j < 10; j++)
			{
				if (format[i + 1] == precision[j])
				{
					p += precision[j] - '0';
					i++;
				}
				if (format[i + 1] == specifiers[j])
				{
					if (j >= 2 && j <= 4)
						count += ptr[2](ap, j, p);
					else if (j >= 5 && j <= 8)
						count += ptr[3](ap, j, p);
					else if (j == 1 || j == 9)
						count += ptr[1](ap, j, p);
					else
						count += ptr[j](ap, j, p);
					i++;
					break;
				}
			}
		}
		else
			count += _putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (count);
}
