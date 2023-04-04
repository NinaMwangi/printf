#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

/*void printAll(const char *format)
{
	while (*format != '\0')
	{
		write(1, &(*format), 1);
		format++;
	}
}*/

/**
 * _printf - produces output according to a format
 * @format: the string with the format specifiers
 * Return: numb of chars printed to std output*
 */

int _printf(const char *format, ...)
{
	va_list list;
	int count;
	char *pH, *nullp;
	char ch;

	nullp = "(null)";
	count = 0;
	va_start(list, format);

	if (format == NULL)
		return (-1);

	while (*format != '\0')
	{

		if (*format == '%' && *(format + 1) == '\0')
		{
			return (-1);
		}
		else if (*format == '%')
		{
			format++;

			if (*format == 'c')
			{
				ch = va_arg(list, int);
				write(1, &ch, 1);
				count++;
				format++;
			}
			else if (*format == 's')
			{
				pH = va_arg(list, char *);

				if (pH == NULL)
                                {
                                        while (*nullp != '\0')
                                        {
                                                write(1, &(*nullp), 1);
                                                nullp++;
                                                count++;
                                        }
					format++;
                                }
                                else
                                {
                                        while (*pH != '\0')
					{
                                        write(1, &(*pH), 1);
                                        pH++;
                                        count++;
					}

					format++;
                                }
			}
			else if (*format == '%')
			{
				ch = '%';
				write(1, &ch, 1);
				format++;
				count++;
			}
			else
			{
				format--;
				write(1, &(*format), 1);
				format++;
				count++;
			}
		}
		else
		{
			write(1, &(*format), 1);
			format++;
			count++;
		}
	}
	va_end(list);
	return (count);
}
