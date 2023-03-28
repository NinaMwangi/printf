#include "main.h"
#include <stdio.h>
#include <stdarg.h>


/**
 * _printf - produces output according to a format
 * @format: the string with the format specifiers
 * Return: numb of chars printed to std output*
 */

int _printf(const char *format, ...)
{
	va_list list;
	int count;
	char *pH;

	count = 0;
	va_start(list, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;

			if (*format == 'c')
			{
				_putchar(va_arg(list, int));
				count++;
				format++;
			}
			else if (*format == 's')
			{
				pH = va_arg(list, char *);

				while (*pH != '\0')
				{
					_putchar(*pH);
					pH++;
					count++;
				}
				format++;
			}
			else if (*format == '%')
			{
				_putchar('%');
				format++;
				count++;
			}
			else
			{
				format++;
			}
		}
		else
		{
			_putchar(*format);
			format++;
			count++;
		}
	}

	va_end(list);
	return (count);
}
