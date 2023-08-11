#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GREATER "Last digit of %d is %d and is greater than 5\n"
#define IS "Last digit of %d is %d and is 0\n"
#define LESS "Last digit of %d is %d and is less than 6 and not 0\n"

/**
  * main - Prints the last digit of a number
  * Description: Prints a different string depending on the value
  * Return: - Returns 0
  */
int main(void)
{
	int n;
	int lastDigit;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	lastDigit = n % 10;
	if (lastDigit > 5)
		printf(GREATER, n, lastDigit);
	else if (lastDigit == 0)
		printf(IS, n, lastDigit);
	else if (lastDigit < 6 && lastDigit != 0)
		printf(LESS, n, lastDigit);
	return (0);
}
