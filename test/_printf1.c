#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - produces output according to a format
 * @format: the string with the format specifiers
 * Return: numb of chars printed to std output*
 */

int _printf(const char *format, ...);

int _putchar(char c);

int main(void)
{
	printf("%d\n", _printf("I am a %s", "boy"));

	return (0);
}

int _putchar(char c)
{
	return (write(1, &c, 1));
}

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
			format++;

                        if (*format == 'c')
                        {
                                _putchar(va_arg(list, int));
                                count++;
                                format++;
                        }
                        else
                        if (*format == 's')
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

                _putchar(*format);
                format++;
                count++;
        }

        va_end(list);
        return (count);
}
