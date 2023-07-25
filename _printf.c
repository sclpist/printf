#include <limits.h>
#include <stdio.h>
#include "main.h"

#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	int count = 0;

	while (*format)
	{
		if (*format == '%')
		{
			format++; // Move past the '%'
			if (*format == '\0')
				break;

			if (*format == '%')
			{
				putchar('%');
				count++;
			}
			else if (*format == 'c')
			{
				char c = (char)va_arg(args, int);
				putchar(c);
				count++;
			}
			else if (*format == 's')
			{
				const char *s = va_arg(args, const char *);
				while (*s)
				{
					putchar(*s);
					s++;
					count++;
				}
			}
		}
		else
		{
			putchar(*format);
			count++;
		}

		format++;
	}

	va_end(args);
	return count;
}
