#include "main.h"

/**
 * factorial - Returns the factorial of a given number
 * @n: An integer
 * Return: The factorial of n
 */
int factorial(int n)
{
	if (n == 1)
		return (1);
	if (n < 0)
		return (-1);
	return (n * factorial(n - 1));
}
