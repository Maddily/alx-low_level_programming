#include "main.h"

/**
 * print_times_table - Prints n times table
 * @n: An integer whose times table is to be printed
 */
void print_times_table(int n)
{
	int i, j;

	if (n > 15 || n < 0)
		return;
	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= n; j++)
		{
			int product = i * j;
			int next_product = i * (j + 1);

			if (product > 9 && product < 100)
			{
				_putchar((product / 10) + '0');
				_putchar((product % 10) + '0');
			}
			else if (product >= 100)
			{
				_putchar((product / 100) + '0');
				_putchar(((product / 10) % 10) + '0');
				_putchar((product % 10) + '0');
			}
			else
				_putchar(product + '0');
			if (j == n)
				break;
			_putchar(',');
			_putchar(' ');
			if (next_product > 9 && next_product < 100)
				_putchar(' ');
			else if (next_product <= 9)
			{
				_putchar(' ');
				_putchar(' ');
			}
		}
		_putchar('\n');
	}
}
