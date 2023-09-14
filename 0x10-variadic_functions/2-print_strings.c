#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_strings - Prints strings, followed by a new line.
 * @separator: The string to be printed between strings
 * @n: The number of strings passed to the function
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list ap;
	unsigned int i;
	char *str;

	va_start(ap, n);

	if (n > 0)
	{
		for (i = 0; i < n; i++)
		{
			str = va_arg(ap, char *);

			printf("%s", (str != NULL) ? str : "(nil)");

			if (separator != NULL && i != n - 1)
				printf("%s", separator);
		}
	}

	printf("\n");
	va_end(ap);
}
