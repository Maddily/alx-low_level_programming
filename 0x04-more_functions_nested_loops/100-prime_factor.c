#include <stdio.h>
#include <math.h>

/**
 * main - Finds and prints the largest prime factor of a number
 * Return: 0
 */
int main(void)
{
	unsigned long number = 612852475143;
	int largestPrimeFactor = 1;
	int i;

	for (i = 2; i <= sqrt(number); i++)
	{
		if (number % i == 0)
		{
			largestPrimeFactor = i;
			while (number % i == 0)
				number /= i;
		}
	}

	if (number > 2)
		largestPrimeFactor = number;

	printf("%d\n", largestPrimeFactor);

	return (0);
}
