#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_all - Prints anything.
 * @format: A list of types of arguments
 */
void print_all(const char * const format, ...)
{
	va_list ap;
	char cr, *str;
	const char *fmt;
	int intgr, first_arg = 1;
	double flt;

	if (format != NULL)
	{
		va_start(ap, format);
		fmt = format;
		while (*fmt)
		{
			if (!first_arg && (*(fmt - 1) == 'c' || *(fmt - 1) == 'i'
					|| *(fmt - 1) == 'f' || *(fmt - 1) == 's'))
				printf(", ");

			switch (*fmt++)
			{
			case 'c':
				cr = (char)va_arg(ap, int);
				printf("%c", cr);
				break;
			case 'i':
				intgr = va_arg(ap, int);
				printf("%d", intgr);
				break;
			case 'f':
				flt = va_arg(ap, double);
				printf("%f", flt);
				break;
			case 's':
				str = va_arg(ap, char *);
				printf("%s", (str != NULL) ? str : "(nil)");
				break;
			}
			first_arg = 0;
		}
	}
	printf("\n");
	va_end(ap);
}
