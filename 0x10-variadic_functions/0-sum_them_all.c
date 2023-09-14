#include <stdarg.h>
#include "variadic_functions.h"

/**
 * sum_them_all - Sums all its parameters
 * @n: The count of the numbers
 * @...: The variable argument numbers
 * Return: The sum of all parameters, or 0 if n is 0
 */
int sum_them_all(const unsigned int n, ...)
{
	unsigned int i;
	int sum;
	va_list arg;

	if (n == 0)
		return (0);

	va_start(arg, n);

	sum = 0;
	for (i = 0; i < n; i++)
		sum += va_arg(arg, int);

	va_end(arg);
	return (sum);
}
