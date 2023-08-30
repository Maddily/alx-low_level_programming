#include "main.h"

/**
 * helper - Checks if a number is a prime number using recursion
 * @num: A number less than n
 * @n: The number to be checked
 * Return: 1 if it's a prime number, 0 otherwise
 */
int helper(int num, int n)
{
	if (num == 1)
		return (1);

	if (n % num == 0)
		return (0);

	return (helper(num - 1, n));
}

/**
 * is_prime_number - Checks if a number is a prime number
 * @n: An integer
 * Return: 1 if n is a prime number, 0 otherwise
 */
int is_prime_number(int n)
{
	int num = n - 1;

	if (n <= 1)
		return (0);

	return (helper(num, n));
}
