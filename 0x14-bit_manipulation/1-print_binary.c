#include "main.h"

/**
 * print_binary - Prints the binary representation of a number
 * @n: The number to be converted to base 2 and printed
 */
void print_binary(unsigned long int n)
{
	unsigned long int i;

	if ((long)n < 0)
		return;
	if (n == 0)
	{
		_putchar('0');
		return;
	}

	i = 1;
	while (i <= n)
		i *= 2;

	i = i >> 1;

	while (i > 0)
	{
		if (n >= i)
		{
			_putchar('1');
			n -= i;
		}
		else
			_putchar('0');

		i = i >> 1;
	}
}
