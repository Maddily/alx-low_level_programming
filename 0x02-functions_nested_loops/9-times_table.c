#include "main.h"

/**
 * times_table - Prints the 9 times table
 */
void times_table(void)
{
	int i;
	int j;

	for (i = 0; i <= 9; i++)
	{
		for (j = 0; j <= 9; j++)
		{
			int product = i * j;
			int next_product = i * (j + 1);

			if (product > 9)
			{
				_putchar((product / 10) + '0');
				_putchar((product % 10) + '0');
				if (j == 9)
					break;
			}
			else
			{
				_putchar(product + '0');
				if (j == 9)
					break;
			}
			if (next_product > 9)
			{
				_putchar(',');
				_putchar(' ');
			}
			else
			{
				_putchar(',');
				_putchar(' ');
				_putchar(' ');
			}
		}
		_putchar('\n');
	}
}
