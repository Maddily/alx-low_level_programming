#include "main.h"

/**
 * print_number - Prints an integer
 * @n: An integer
 */
void print_number(int n)
{
	unsigned int number = n;

	if (n < 0)
	{
		_putchar('-');
		number = -number;
	}
	if (number >= 10)
	{
		print_number(number / 10);
	}

	_putchar('0' + (number % 10));
}
