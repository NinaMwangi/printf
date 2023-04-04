#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#define BITS_IN_INT (sizeof(int) * 8)

/**
 * printAll - ...
 * @format: ...
 */

int printAll(int format, int count)
{
        char toStr[20];
        char *p;

        sprintf(toStr, "%d", format);

        p = toStr;
        while (*p != '\0')
        {
                write(1, &(*p), 1);
                p++;
                count ++;
        }

        return (count);
}

char* toBinary(int num) {

    char* buffer = (char*) malloc(sizeof(char) * (BITS_IN_INT + 1)), *newBuffer;
    unsigned int mask = 1 << (BITS_IN_INT - 1);
    long unsigned int i;
    int firstNonZero = -1, newSize;

    if (!buffer) {
        fprintf(stderr, "Error: could not allocate memory for binary string buffer\n");
        return NULL;
    }
    buffer[BITS_IN_INT] = '\0';

    for (i = 0; i < BITS_IN_INT; i++) {
        buffer[i] = (num & mask) ? '1' : '0';
        mask >>= 1;
        if (buffer[i] == '1' && firstNonZero == -1) {
            firstNonZero = i;
        }
    }

    if (firstNonZero == -1) {
        firstNonZero = BITS_IN_INT - 1;
    }

    newSize = BITS_IN_INT - firstNonZero;
    newBuffer = (char*) realloc(buffer, sizeof(char) * (newSize + 1));
    if (!newBuffer) {
        fprintf(stderr, "Error: could not allocate memory for new binary string buffer\n");
        return NULL;
    }

    newBuffer[newSize] = '\0';
    memcpy(newBuffer, buffer + firstNonZero, newSize);

    return newBuffer;
}


/**
 * _printf - produces output according to a format
 * @format: the string with the format specifiers
 * Return: numb of chars printed to std output*
 */

int _printf(const char *format, ...)
{
	va_list list;
	int count, numb;
	char *pH, *nullp, *temp;
	char ch;
	unsigned int numb1;

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
			else if (*format == 'd' || *format == 'i')
			{
				numb = va_arg(list, int);
				count = printAll(numb, count);
				format++;
			}
			else if (*format == 'b')
			{
				numb1 = va_arg(list, int);
				temp = toBinary(numb1);

				while (*temp != '\0')
                                          {
                                                 write(1, &(*temp), 1);
                                                 temp++;
                                                 count++;
                                          }
				format++;
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
