#include "main.h"

/**
 * print_diagonal - Draws a diagonal line
 * @n: The number of \ characters to be printed
 */
void print_diagonal(int n)
{
	int i, j;

	if (n > 0)
	{
		_putchar('\\');
		_putchar('\n');
		for (i = 0; i < n - 1; i++)
		{
			for (j = 0; j <= i; j++)
				_putchar(' ');
			_putchar('\\');
			_putchar('\n');
		}
	}
	else
		_putchar('\n');
}
