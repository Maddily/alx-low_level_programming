#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_numbers - Prints numbers, followed by a new line.
 * @separator: The string to be printed between numbers.
 * @n: The number of integers passed to the function.
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list ap;
	unsigned int i;

	va_start(ap, n);

	if (n > 0)
	{
		for (i = 0; i < n; i++)
		{
			printf("%d", va_arg(ap, int));

			if (separator != NULL && i != n - 1)
				printf("%s", separator);
		}
	}

	printf("\n");
	va_end(ap);
}
