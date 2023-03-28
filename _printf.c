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
	int count = 0;
	char *pH;

	va_start(list, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			if (*(format + 1) == 'c')
			{
				_putchar(va_arg(list, int));
				count++;
				format += 2;
			}
			else
			if (*(format + 1) == 's')
			{
				pH = va_arg(list, char *);

				while (*pH != '\0')
				{
					_putchar(*pH);
					pH++;
					count++;
				}
				format += 2;
			}
			else if (*(format + 1) == '%')
			{
				_putchar('%');
				format += 2;
				count++;
			}
		}

		_putchar(*format);
		format++;
		count++;
	}

	va_end(list);
	return (count);
}
