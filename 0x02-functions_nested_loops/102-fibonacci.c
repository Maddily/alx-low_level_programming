#include <stdio.h>

/**
 * main - Print the first fibonacci numbers
 * Return: Returns 0
 */
int main(void)
{
	unsigned long long fib_numbers[50] = {1, 2};
	size_t i;

	printf("1, 2");

	for (i = 2; i < 50; i++)
	{
		fib_numbers[i] = fib_numbers[i - 1] + fib_numbers[i - 2];
		printf(", %llu", fib_numbers[i]);
	}

	printf("\n");

	return (0);
}
