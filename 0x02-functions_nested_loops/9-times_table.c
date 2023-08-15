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

			if (product > 9)
			{
				_putchar((product / 10) + '0');
				_putchar((product % 10) + '0');
				if (j == 9)
					break;
				_putchar(',');
				_putchar(' ');
			}
			else
			{
				_putchar(product + '0');
				if (j == 9)
					break;
				_putchar(',');
				_putchar(' ');
				_putchar(' ');
			}
		}
		_putchar('\n');
	}
}
