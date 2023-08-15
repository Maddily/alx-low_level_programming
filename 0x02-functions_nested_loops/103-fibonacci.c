#include <stdio.h>

/**
 * main - Print the sum of even fibonacci numbers below 4,000,000
 * Return: Returns 0
 */
int main(void)
{
	unsigned long fib_numbers[40] = {1, 2}, sum = 2;
	size_t i;

	for (i = 2; i < 40; i++)
	{
		fib_numbers[i] = fib_numbers[i - 1] + fib_numbers[i - 2];
		if (fib_numbers[i] > 4000000)
			break;
		if (fib_numbers[i] % 2 == 0)
			sum += fib_numbers[i];
	}

	printf("%lu\n", sum);

	return (0);
}
