#include <stdio.h>

/**
 * main - Calculate and print the sum of the multiples of 3 and 5
 * Return: Returns 0
 */
int main(void)
{
	int i, sum;

	for (i = 3; i < 1024; i++)
	{
		if (i % 3 || i % 5)
		{
			sum += i;
			i++;
		}
	}
	printf("%d\n", sum);
	return (0);
}
