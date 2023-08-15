#include <stdio.h>

/**
 * main - Print the first 98 fibonacci numbers
 * Return: Returns 0
 */
int main(void)
{
	unsigned long n1 = 1, n2 = 2, fib_number;
	size_t i;

	printf("1, 2");

	for (i = 2; i < 98; i++)
	{
		fib_number = n1 + n2;
		n1 = n2;
		n2 = fib_number;
		printf(", %lu", fib_number);
	}

	printf("\n");

	return (0);
}
