#include <stdio.h>
#include "main.h"

/**
 * print_to_98 - Prints natural numbers from n to 98
 * @n: Integer to print from
 */
void print_to_98(int n)
{
	if (n <= 98)
	{
		while (n <= 98)
		{
			printf("%d", n);
			if (n == 98)
				break;
			printf(", ");
			n++;
		}
		printf("\n");
	}
	else
	{
		while (n >= 98)
		{
			printf("%d", n);
			if (n == 98)
				break;
			printf(", ");
			n--;
		}
		printf("\n");
	}
}
