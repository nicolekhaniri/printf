#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - Write a function that produces output according to a format
 * @format: pointer to a string
 * Return: number of printed characters
 *
 */

int _printf(const char *format, ...)
{
	int i;
	char n = '\n';
	char space = ' ';
	int position = 0;
	va_list args;

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == ' ')
		{
			write(1, &space, 1);
			position = position + 1;
		}
		else if (format[i] == '%')
		{
			int j = i + 1;

			if (format[j] == 'c')
			{
				int x = va_arg(args, int);

				write(1, &x, 1);
				i += 1;
				position += 1;
			}
			else if (format[j] == 's')
			{
				int k = 0;

				char *n = va_arg(args, char *);

				while (n[k] != '\0')
				{
					write(1, &n[k], 1);
					k += 1;
				}
				i += 1;
			}
		}
		else
		{
			write(1, &format[i], 1);
			position += 1;
		}
	}
	write(1, &n, 1);
return (position);
}
